import java.util.*;
public class 별찍기19 {
	static int dx[]={-1,0,1,0};
	static int dy[]= {0,1,0,-1};
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		StringBuilder sb=new StringBuilder();
		int n=sc.nextInt();
		int x=4*(n-1)+1;
		String s[][]=new String[x][x];
		for(int i=0;i<x;i++) {
			for(int j=0;j<x;j++) {
				s[i][j]=" ";
			}
		}
		go(s,0,0,x);
		for(int i=0;i<x;i++) {
			for(int j=0;j<x;j++) {
				sb.append(s[i][j]);
			}
			sb.append("\n");
		}
		System.out.println(sb.toString());
	}
	static void go(String s[][],int x,int y,int cnt) {
		if(cnt==1) {
			s[x][y]="*";
		}else {
			for(int i=0;i<cnt;i++) {
				s[x+i][y]="*";
				s[x][y+i]="*";
				s[x+cnt-1][y+i]="*";
				s[x+i][y+cnt-1]="*";
			}
			go(s,x+2,y+2,cnt-4);
			
		}
	}
}
