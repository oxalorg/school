import java.io.*;			
import java.net.*;			
import java.util.*;			

class Server {
	public static void main(String args[]) throws IOException {
		try(
			ServerSocket ss = new ServerSocket(2225);	
			
		){	
			Socket client = ss.accept();
			ClientWrite cl = new ClientWrite(client);
			cl.start();
			BufferedReader br = new BufferedReader(new InputStreamReader(client.getInputStream()));
			String msg;
			while(true){
					msg = br.readLine();
				System.out.println("Client: " + msg);
			}	
		} catch (Exception e) {
			System.out.println(e);	
		}	
			
	}	
}

class ClientWrite extends Thread {
	Socket client;
		
	ClientWrite (Socket client) {
		this.client = client;
	}

	public void run() {
		try {
			PrintWriter pw = new PrintWriter(client.getOutputStream(), true);
			BufferedReader brSys = new BufferedReader(new InputStreamReader(System.in));
			String inMsg;
			while((inMsg = brSys.readLine()) != null) {
				pw.println(inMsg);	
				//	System.out.println(br.readLine());
			}
		} catch (Exception e) {
			System.out.println(e);
		}
	}
}
