import java.io.*;
import java.net.*;
import java.util.*;

class MultiClient
{
	/* 	
		Echos user string to 'MultiServer'
		'MultiServer' will create a thread for each new client connected
		and echo the string back
	*/	
	public static void main(String[] args) {
		// Set up a connection in try with else block
		// Benefits of automatic closing of all the streams in reverse order
		if (args.length != 1) {
        	System.err.println("Usage: java MultiClient <Server Ip Address>");
        	System.exit(1);
    	}

		try (
			// Binding client to the below socket on localhost
			Socket clientSocket = new Socket(args[0], 8001);
			// Opening a decorated input stream for userinput
			BufferedReader stdIn = new BufferedReader(new InputStreamReader (System.in));
			// Opening a decorated input stream for the socket
			// used to read data from the socket
			BufferedReader in = new BufferedReader(new InputStreamReader (clientSocket.getInputStream()));
			// Opening an output writer stream for the socket
			// used to write data to the socket stream 
			// flush is set to true
			PrintWriter out = new PrintWriter(clientSocket.getOutputStream(), true);
		){
			String userInput;
			System.out.println("Enter a string.");
			while((userInput = stdIn.readLine()) != null){
				out.println(userInput);
				System.out.println("echo: " + in.readLine());
			}
		}
		 catch (Exception e){
			System.out.println(e);
		}
	}
}