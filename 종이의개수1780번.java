import java.util.*;
import java.io.*;
public class 종이의개수1780번 {
	static 	int a=0;
	static	int b=0;
	static	int c=0;
	public static void main(String[] args) throws IOException{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int n=Integer.parseInt(br.readLine());
		int d[][]=new int[n][n];
		
		for(int i=0;i<n;i++) {
			String s[]=br.readLine().split(" ");
			for(int j=0;j<n;j++) {
				d[i][j]=Integer.parseInt(s[j]);
			}
		}
		sort(n,d,0,0);
		System.out.println(a+"\n"+b+"\n"+c);
	}
	public static void sort(int n,int d[][],int x,int y) {
		if(!same(n,d,x,y)) {
			n=n/3;
			sort(n,d,x,y);
			sort(n,d,x,y+n);
			sort(n,d,x,y+n+n);
			sort(n,d,x+n,y);
			sort(n,d,x+n,y+n);
			sort(n,d,x+n,y+n+n);
			sort(n,d,x+n+n,y);
			sort(n,d,x+n+n,y+n);
			sort(n,d,x+n+n,y+n+n);
		}
	}
	public static boolean same(int n,int d[][],int x,int y) {
		for(int i=x;i<x+n;i++) {
			for(int j=y;j<y+n;j++) {
				if(d[x][y]!=d[i][j]) {
					return false;
				}
			}
		}
		if(d[x][y]==-1) {
			a++;
		}else if(d[x][y]==0) {
			b++;
		}else{
			c++;
		}
		return true;
	}
	

}
