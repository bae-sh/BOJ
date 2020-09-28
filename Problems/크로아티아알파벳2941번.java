package 백준;
import java.util.*;
public class 크로아티아알파벳2941번 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		String s=sc.nextLine();
		int cnt=0;
		for(int i=0;i<s.length();i++) {
			if(i!=s.length()-1) {
				if(s.charAt(i)=='c'&&(s.charAt(i+1)=='='||s.charAt(i+1)=='-')) {
					cnt++;
					i++;
					continue;
				}else if(s.charAt(i)=='d'&&s.charAt(i+1)=='-') {
					cnt++;
					i++;
					continue;
				}else if(i!=s.length()-2&&s.substring(i, i+3).equals("dz=")) {
					cnt++;
					i+=2;
					continue;
				}else if(s.charAt(i)=='l'&&s.charAt(i+1)=='j') {
					cnt++;
					i++;
					continue;
				}  else if(s.charAt(i)=='n'&&s.charAt(i+1)=='j') {
					cnt++;
					i++;
					continue;
				}  else if(s.charAt(i)=='s'&&s.charAt(i+1)=='=') {
					cnt++;
					i++;
					continue;
				}  else if(s.charAt(i)=='z'&&s.charAt(i+1)=='=') {
					cnt++;
					i++;
					continue;
				} 
			}
			cnt++;
		}
		System.out.println(cnt);
	}

}
