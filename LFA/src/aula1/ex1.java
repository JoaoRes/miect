package aula1;

import java.util.*;
 


public class ex1 {
	

	static Scanner sc = new Scanner(System.in);
	
	public static void main(String[] args) 
	{
		double num1, num2, result=0;
		String op;
		boolean f=true;

		System.out.print(">>");
		String operation = sc.nextLine();
		
		String[] arrofStr= operation.split(" ", 3);
		
		
		num1=Double.parseDouble(arrofStr[0]);
		
		op=arrofStr[1];
		
		num2=Double.parseDouble(arrofStr[2]);
		
		
		switch(op) 
		{
			case "+":
				result = num1+num2;
				break;
			case "-":
				result = num1-num2;
				break;
			case "*":
				result = num1*num2;
				break;
			case "/":
				result = num1/num2;
				break;
			default :
				f= false;
				System.err.println("operador invalido");
		}
		
		if(!f)System.out.println(result);
	}
	
}

