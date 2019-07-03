import java.util.*;
public class 소용돌이예쁘게출력하기 {
	static int dx[]= {0,-1,0,1};
	static int dy[]= {-1,0,1,0};
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int max=0;
		int r1=sc.nextInt();
		int c1=sc.nextInt();
		int r2=sc.nextInt();
		int c2=sc.nextInt();
		int r=-r1;
		int c=-c1;
		int d[][]=new int[r2-r1+1][c2-c1+1];
		for(int i=r1;i<=r2;i++) {
			for(int j=c1;j<=c2;j++) {
				if(i<=0&&Math.abs(j)<=Math.abs(i)) {
					d[i+r][j+c]=4*i*i+1+i-j;
				}else if(j>0&&Math.abs(j)>Math.abs(i)) {
					d[i+r][j+c]=4*j*j+1-3*j-i;
				}else if(i>0&&Math.abs(i)>=Math.abs(j)) {
					d[i+r][j+c]=(int)Math.pow(2*i+1, 2)+j-i;
				}else if(j<0&&Math.abs(j)>Math.abs(i)) {
					d[i+r][j+c]=4*j*j+1+i-j;
				}
				max=Math.max(max, d[i+r][j+c]);
			}
		}
		String s=Integer.toString(max);
		int len=s.length();
		for(int i=0;i<=r2-r1;i++) {
			for(int j=0;j<=c2-c1;j++) {
				String t=Integer.toString(d[i][j]);
				for(int k=0;k<len-t.length();k++) {
					System.out.print(" ");
				}
				System.out.print(t+" ");
			}
			System.out.println();
		}
	}

}
