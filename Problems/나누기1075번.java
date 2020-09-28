package 백준;
import java.util.*;
public class 나누기1075번 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		String a=sc.next();
		int b=sc.nextInt();
		String a2="";
		for(int i=0;i<a.length()-2;i++) {
			a2+=a.charAt(i);
		}
		a2+="00";
		int c=Integer.parseInt(a2);
		for(int i=0;i<b;i++) {
			if((c+i)%b==0) {
				a=Integer.toString(c+i);
				System.out.println(a.substring(a.length()-2, a.length()));
				break;
			}
		}
	}

}
