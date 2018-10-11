package 백준;
import java.util.*;
public class 두교수7888번 {
	static boolean p(int x,int y,int a[][],int k) {
		if(a[k][x]==1) {
			return false;
		}
		if(a[k][y]==1) {
			return false;
		}
		for(int i=x+1;i<y;i++) {
			if(a[k][i]!=0) {
				return false;
			}
		}
		for(int i=x+1;i<y;i++) {
			a[k][i]=1;
		}
		return true;
	}
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int t=sc.nextInt();
		for(int i=0;i<t;i++) {
			int n=sc.nextInt();
			int ans=0;
			int a[][]=new int[n][1000000000];
			for(int j=0;j<n;j++) {
				int x=sc.nextInt();
				int y=sc.nextInt();
				for(int k=0;k<n;k++) {
					if(p(x,y,a,k)==true) {
						break;
					}
				}
			}
		}
	}

}
