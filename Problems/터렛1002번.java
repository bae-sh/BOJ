package 백준;
import java.util.*;
public class 터렛1002번 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		for(int i=0;i<n;i++) {
			long x1=sc.nextInt(); 
			long y1=sc.nextInt(); 
			long r1=sc.nextInt();
			long x2=sc.nextInt(); 
			long y2=sc.nextInt();
			long r2=sc.nextInt(); 
			long r=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
			if(r==0) {
				if(r1==r2) {
					System.out.println(-1);
				}
				else {
					System.out.println(0);
				}
			}
			else if(r==Math.pow(r1+r2, 2)) {
				System.out.println(1);
			}
			else if(r>Math.pow(r1+r2, 2)) {
				System.out.println(0);
			}
			else if(r<Math.pow(r1+r2, 2)) {
				if(r>Math.max(r1, r2)*Math.max(r1, r2)) {
					System.out.println(2);
				}
				else {
					if(r<Math.pow(Math.max(r1, r2)-Math.min(r1, r2), 2)) {
						System.out.println(0);
					}
					else if(r>Math.pow(Math.max(r1, r2)-Math.min(r1, r2), 2)) {
						System.out.println(2);
					}
					else {
						System.out.println(1);
					}
				}
			}
		}
	}

}
