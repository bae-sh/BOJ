package 백준;
import java.util.*;
public class 한수1065번 {
	
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int cnt=0;
		outerloop:
		for(int i=1;i<=n;i++) {
			if(i<100) {
				cnt++;
				continue;
			}
			int a=Integer.toString(i).charAt(0)-Integer.toString(i).charAt(1);
			for(int j=0;j<Integer.toString(i).length()-1;j++) {
				if(Integer.toString(i).charAt(j)-Integer.toString(i).charAt(j+1)!=a) {
					continue outerloop;
				}
			}
			cnt++;
		}
		System.out.println(cnt);
	}

}
