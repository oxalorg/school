import java.io.*;
import java.net.*;
import java.util.*;

class MultiServer{
	public static void main(String[] args) {
		// Set up a connection in try with else block
		// Benefits of automatic closing of all the streams in reverse order
		try (
			ServerSocket serverSocket = new ServerSocket(8001);
		){
			while(true){
				try {
					// Accepts the nex client connection request from the connection queue
					Socket clientSocket = serverSocket.accept();
					// and passes it to the thread class to start execution
					new MultiServerThread(clientSocket).start();
				} catch (Exception e){
					System.out.println("0. " + e);
				}
			}
		} catch (Exception e){
				System.out.println("1. " + e);
		}
	}
}

class MyServerProtocol{
	/*	
	*	Logic of communication between the client and server resides here.
	* 	Update the processInput() function depending on your needs.
	*/	
	public String processInput(String inputLine){
		String processedLine;
		processedLine = inputLine.toUpperCase();
		return (processedLine);
	}
}

class MultiServerThread extends Thread {
	private Socket clientSocket = null;

	public MultiServerThread(Socket clientSocket){
		super("MultiServerThread");
		this.clientSocket = clientSocket;
	} 

	public void run(){
		try (
			BufferedReader in = new BufferedReader(new InputStreamReader (clientSocket.getInputStream()));
			PrintWriter out = new PrintWriter(clientSocket.getOutputStream(), true);
		){
			String inputLine, outputLine;
			// Create a protocol instance to deal with the input and process it.
			MyServerProtocol msp = new MyServerProtocol();

			System.out.println("Reading from client.. ");
			while((inputLine = in.readLine()) != null){
				outputLine = msp.processInput(inputLine);
				out.println(outputLine);
				System.out.println("The proccessed line has been sent to client: " + 
					clientSocket.getInetAddress() + ":" +clientSocket.getLocalPort());
			}
		} catch (Exception e){
			System.out.println(e);
		} finally {
			try { 
				clientSocket.close();  
			} catch (Exception e){
				System.out.println(e);
			}
		}
	}
}