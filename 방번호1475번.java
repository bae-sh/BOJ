package 백준;
import java.util.*;
public class 방번호1475번 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int a[]=new int[10];
		String s=sc.nextLine();
		for(int i=0;i<s.length();i++) {
			if(s.charAt(i)=='6'||s.charAt(i)=='9') {
				a[6]++;
			}else {
				a[Integer.parseInt(s.charAt(i)+"")]++;
			}
		}
		if(a[6]%2==0) {
			a[6]=a[6]/2;
		}else {
			a[6]=a[6]/2+1;
		}
		
		Arrays.sort(a);
		System.out.println(a[9]);
	}

}
