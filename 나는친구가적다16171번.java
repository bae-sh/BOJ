package 백준;
import java.util.*;
import java.io.*;
public class 나는친구가적다16171번  {

	public static void main(String[] args) throws IOException{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		String x=br.readLine();
		String ans=br.readLine();
		char[] array=x.toCharArray();
		x="";
		for(int i=0;i<array.length;i++) {
			if('0'<=array[i]&&array[i]<='9') {
				continue;
			}else {
				x+=array[i]+"";
			}
		}
		for(int i=0;i<x.length();i++) {
			if(ans.charAt(0)==x.charAt(i)) {
				if(x.length()-i>=ans.length()) {
					if(ans.equals(x.substring(i, i+ans.length()))) {
					System.out.println(1);
					System.exit(0);
					}
				}
			}
		}
		System.out.println(0);
		System.exit(0);
		
	}

}
