package aula1;

import java.util.*;
 


public class ex2 {
	

    static Scanner sc = new Scanner(System.in);
    static Stack<Double> storage = new Stack<Double>();
	
	public static void main(String[] args) 
	{
        System.out.println("Type your values in Reverse Polish Notation");
        String calc = sc.nextLine();
        String[] prestack = calc.split(" ");
        int indOp=0;
        
        for(int i=0 ; i< prestack.length ; i++)
        {
            
            if(prestack[i].matches("[0-9]+"))
            {
                storage.add(Double.parseDouble(prestack[i]));
                System.out.println("Stack: "+storage);
            }
            else
            {
                indOp=i;
                break;
                
            }
        }

        for(int i=indOp ; i<prestack.length ; i++){
            switch(prestack[i]) 
                {
                    case "+":
                        storage.add(storage.pop()+storage.pop());
                        System.out.println("Stack: "+storage);
                         break;
                     case "-":
                        storage.add(storage.pop()-storage.pop());
                        System.out.println("Stack: "+storage);
                         break;
                     case "*":
                        storage.add(storage.pop()*storage.pop());
                        System.out.println("Stack: "+storage);
                         break;
                     case "/":
                        storage.add(storage.pop()/storage.pop());
                        System.out.println("Stack: "+storage);
                         break;
                     default :
                        System.err.println("operador invalido");
                } 
        }
	}
	
}

