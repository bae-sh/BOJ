package 백준;
import java.util.*;
public class 오와육의차이2864번 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		String a=sc.next();
		String b=sc.next();
		String aa="";
		String bb="";
		int max,min;
		for(int i=0;i<a.length();i++) {
			
			if(a.charAt(i)=='5') {
				aa+="6";
			}else {
				aa+=a.charAt(i)+"";
			}
		}
		for(int i=0;i<b.length();i++) {
			
			if(b.charAt(i)=='5') {
				bb+="6";
			}else {
				bb+=b.charAt(i)+"";
			}
		}
		max=Integer.parseInt(aa)+Integer.parseInt(bb);
		aa="";
		bb="";
		for(int i=0;i<a.length();i++) {
			
			if(a.charAt(i)=='6') {
				aa+="5";
			}else {
				aa+=a.charAt(i)+"";
			}
		}
		for(int i=0;i<b.length();i++) {
			
			if(b.charAt(i)=='6') {
				bb+="5";
			}else {
				bb+=b.charAt(i)+"";
			}
		
		}
		min=Integer.parseInt(aa)+Integer.parseInt(bb);
		System.out.println(min+" "+max);
		
	}

}
