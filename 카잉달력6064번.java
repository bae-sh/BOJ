package 백준;
import java.util.*;
public class 카잉달력6064번 {
	public static int gcd(int a, int b) {
	    while (b != 0) {
	      int temp = a % b;
	      a = b;
	      b = temp;
	    }
	    return a;
	  }

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		
		int n=sc.nextInt();
		for(int i=0;i<n;i++) {
			Queue<Integer> q=new LinkedList();
			int a=sc.nextInt();
			int b=sc.nextInt();
			int c=sc.nextInt();
			int d=sc.nextInt();
			int j=0;
			while(a*j+c<=a*b/gcd(a,b)) {
				int s= a*j+c;
				q.add(s);
				j++;
			}
			boolean z=false;
			while(!q.isEmpty()) {
				int s=q.poll();
				if(s%b==d&&b!=d) {
					System.out.println(s);
					z=true;
				}
				else if(s%b+b==d) {
					System.out.println(s);
					z=true;
				}
			}
			if(z==false) {
				System.out.println(-1);
			}
		}
	}

}
