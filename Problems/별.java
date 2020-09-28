import java.util.*;
public class 별 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		StringBuilder sb=new StringBuilder();
		if(n==0)
			System.out.println("*");
		else if(n==1) {
			System.out.println("**");
			System.out.println("*");
		}
		else {
			int dn=(int)Math.pow(2, n);
			String a[][]=new String[dn][dn];
			for(int i=0;i<dn;i++) {
				for(int j=0;j<dn;j++) {
					a[i][j]=" ";
				}
			}
			go(n,a,0,0);
			for(int i=0;i<dn;i++) {
				for(int j=0;j<dn;j++) {
					if(i+j>dn-1)
						break;
					else {
						sb.append(a[i][j]);
					}
				}
				sb.append("\n");
			}
			System.out.println(sb.toString());
		}
	}
	public static void go(int n,String a[][],int x,int y) {
		if(n==2) {
			for(int i=0;i<4;i++) {
				for(int j=0;j<4;j++) {
					int nx=x+i,ny=y+j;
					if(i+j>3||(i==1&&j==1)) {
						continue;
					}else {
						a[nx][ny]="*";
					}
				}
			}
		}else {
			n--;
			int dn=(int)Math.pow(2, n);
			go(n,a,x,y);
			go(n,a,x,y+dn);
			go(n,a,x+dn,y);
		}
	}
}
