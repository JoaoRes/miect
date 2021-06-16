package aula1;

import java.util.*;
import java.io.*;

public class ex3
{   
    static HashMap<String, Integer> numbers = new HashMap<String,Integer>();
    static Scanner scn = new Scanner(System.in);
    public static void main(String[] args) throws IOException
    {
        File f = new File("../files/bloco1/numbers.txt");
        Scanner fin = new Scanner(f);

        while(fin.hasNextLine())
        {
            String line = fin.nextLine();
            String[] s = line.split(" - ");
            numbers.put(s[1],Integer.parseInt(s[0]));
        }
        fin.close();

        System.out.println("Write down your values");
        String s = scn.nextLine();

        String[] num = s.split("[ -]+");
        String output="";
        
        for(String a : num)
        {
            output +=(numbers.get(a)+ " ");
        }

        System.out.println(output);
        


    }
}