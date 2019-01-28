package 백준;
import java.util.*;
public class 전화번호목록5052번 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		for(int i=0;i<n;i++) {
			int a=sc.nextInt();
			String d[]=new String[a];
			d[0]=sc.next();
			boolean b=false;
			for(int j=1;j<a;j++) {
				d[j]=sc.next();
				if(d[j].substring(0, d[0].length()).equals(d[0])) {
					b=true;
					break;
				}
				
			}
			if(b==true) {
				System.out.println("NO");
			}else {
				System.out.println("YES");
			}
		}
	}

}
