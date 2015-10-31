import java.io.*;
import java.net.*;
import java.util.*;

class EchoServer
{
	public static void main(String[] args) {
		// Set up a connection in try with else block
		// Benefits of automatic closing of all the streams in reverse order
		try (
			ServerSocket serverSocket = new ServerSocket(8001);
		){
			while(true){
				try (
					Socket clientSocket = serverSocket.accept();
					BufferedReader in = new BufferedReader(new InputStreamReader (clientSocket.getInputStream()));
					PrintWriter out = new PrintWriter(clientSocket.getOutputStream(), true);
				){
					String inputLine, outputLine;
					// Create a protocol instance to deal with the input and process it.
					MyServerProtocol msp = new MyServerProtocol();

					System.out.println("Reading from client.. ");
					while((inputLine = in.readLine()) != null){
						outputLine = msp.processInput(inputLine);
						outputLine = inputLine.toUpperCase();
						out.println(outputLine);
						System.out.println("The proccessed line has been sent to client: " + 
							clientSocket.getInetAddress() + ":" +clientSocket.getLocalPort());
					}
				} catch (Exception e){
					System.out.println(e);
				}
			}
		} catch (Exception e){
				System.out.println(e);
		}
	}
}

class MyServerProtocol
{
	public String processInput(String inputLine){
		return (inputLine);
	}
}
