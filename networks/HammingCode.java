/*
*	Hamming Code creation, detection, correction for 1 bit errors.
* 	Author: @MiteshNinja
*	Date: 2015, November 05
*/

import java.util.*;
import java.lang.*;
import java.io.*;

class HammingCode{
	public static void main(String[] args){
		String data;
		String code = new String();
		Scanner sc = new Scanner(System.in);
		
		// Input Dataword
		System.out.println("Dataword:");
		data = sc.next();

		// Form Codeword without parity
		int len = data.length();
		int i = 1, j = 0;
		while(len != 0){
			if((i & (i-1)) == 0){
				code = code + '0';
				i++;
			} else {
				code = code + data.charAt(j);
				j++;
				i++;
				len--;
			}
		}
		len = i-1;

		// Codeword with parity
		String newCode = new String();
		for (i=1; i <= len ; i++ ) {
			if ((i & (i-1)) == 0) {
				newCode += getParity(code, i);
			} else {
				newCode += code.charAt(i-1);
			}
		}
		System.out.println("Codeword:");
		System.out.println(newCode);

		// Introduce Error
		System.out.print("Introduce error at position: ");
		int error = sc.nextInt();
		String errorCode = newCode.substring(0, error-1) + invertChar(newCode, error-1) + newCode.substring(error);
		System.out.println("ErrorCode:");
		System.out.println(errorCode);
		
		// Detect Error
		int errorAtBit = 0;
		for (i=1; i <= len ; i++ ) {
			if ((i & (i-1)) == 0) {
				char temp = getParity(errorCode, i);
				if(temp == '1'){
					errorAtBit += i;
				}
			}
		}
		System.out.println("Error detected at bit: " + errorAtBit);

		//Corrected code
		int correct = errorAtBit;
		String correctCode = newCode.substring(0, correct-1) + invertChar(errorCode, correct-1) + newCode.substring(correct);
		System.out.println("correctCode:");
		System.out.println(correctCode);
	}
	public static char invertChar(String code, int index){
		if(code.charAt(index) == '1'){
			return '0';
		} else {
			return '1';
		}
	}
	public static char getParity(String code, int index){
		int m = 2*index;
		int len = code.length();
		int counter = 0;
		int i;
		for (i = index; i <= len ; i++ ) {
			int x = code.charAt(i-1) - '0';
			if (i % m >= index) {
				if( x == 1 )
					counter++;	
			}			
		}
		if (counter % 2 == 0) {
			return '0';
		} else {
			return '1';
		}
	}
}