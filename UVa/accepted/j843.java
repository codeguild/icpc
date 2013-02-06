import java.util.*;
//import java.utils.Scanner;

public class j843
{
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		int nwords = sc.nextInt();
		String [] words = new String[nwords];
		for(int i = 0; i < nwords; i++)
		{
			words[i] = sc.next();
		}
		sc.nextLine();
		int i = 0;
		while(sc.hasNext())
		{
			if(i!= 0)
				System.out.println();
			testar(words, sc.nextLine());
			i++;
		}
	}
	public static String f(String frase, char [] hash)
	{
		String str = "";
		for(int i = 0; i < frase.length(); i++)
		{
			if(frase.charAt(i) == ' ')
				str += " ";
			else
				str += hash[frase.charAt(i)-'a'	+ 1];
		}
		return str;
	}
	public static boolean rec(String original, String [] words, String [] frase, char [] hash, char [] rehash, int i)
	{
		if(i >= frase.length)
		{
			System.out.print(f(original, hash));
			return true;
		}
		for(int j = 0; j < words.length; j++)
		{
			if(words[j].length() == frase[i].length())
			{
				char [] hashcp = hash.clone();
				char [] rehashcp = rehash.clone();
				boolean falhou = false;
				for(int k = 0; k < frase[i].length(); k++)
				{
					if(hash[frase[i].charAt(k) - 'a' + 1] == 0 && rehash[words[j].charAt(k) - 'a' + 1] == 0)
					{
						hash[frase[i].charAt(k) - 'a' + 1] = words[j].charAt(k);
						rehash[words[j].charAt(k) - 'a' + 1] = frase[i].charAt(k);
					}
					else if(hash[frase[i].charAt(k) - 'a' + 1] != words[j].charAt(k))
					{
						falhou = true;
						break;
					}
				}
				if(!falhou)
				{
					if (rec(original, words, frase, hash, rehash, i+1) == true)
						return true;
				}
				hash = hashcp;
				rehash = rehashcp;
			}
		}
		return false;
	}

	public static void testar(String[] words, String frase)
	{
		String [] sfrase = frase.split(" ");
		char [] hash = new char[27];
		char [] rehash = new char[27];
		if(!rec(frase, words, sfrase, hash, rehash, 0))
			System.out.print(frase.replaceAll("[a-z]", "*"));
		
	}
}
