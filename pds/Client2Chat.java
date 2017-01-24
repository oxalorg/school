import java.io.*;
import java.net.*;

class Client1
{
	public static void main(String args[]) throws IOException
	{
	
		Socket s3=new Socket("192.168.208.26",2225);
		System.out.println("server is connected");
		ServerWrite sw = new ServerWrite(s3);
		sw.start();
		BufferedReader bf=new BufferedReader(new InputStreamReader(s3.getInputStream()));
		String msg;
		while((msg = bf.readLine()) != null){
		System.out.println("Server:"+msg);
		}

		s3.close();

	}
}
class ServerWrite extends Thread
{
	Socket s3;
	ServerWrite(Socket client){
		s3=client;
	}
	public void run()
	{
		try
		{
			BufferedReader brSys=new BufferedReader(new InputStreamReader(System.in));
			PrintWriter pw=new PrintWriter(s3.getOutputStream(),true);
			String msg;
			while((msg = brSys.readLine()) != null){
				pw.println(msg);
			}
		}
		catch(Exception e)
		{
			System.out.println(e);
		}
	}
}
