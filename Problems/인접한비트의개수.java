import java.util.*;
public class 인접한비트의개수 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int p[][][]=new int[101][101][2];
		p[1][0][0]=1; p[1][0][1]=1;
		for(int i=2;i<=100;i++) {//i가 자리수 j가 인접 비트의수
			for(int j=0;j<i;j++) {
				if(j==0) {
					p[i][j][0]=p[i-1][j][0]+p[i-1][j][1];
					p[i][j][1]=p[i-1][j][0];
				}else {
					p[i][j][0]=p[i-1][j][0]+p[i-1][j][1];
					p[i][j][1]=p[i-1][j][0]+p[i-1][j-1][1];
				}	
			}
		}
		int t=sc.nextInt();
		while(t-->0) {
			int n=sc.nextInt();
			int k=sc.nextInt();
			System.out.println(p[n][k][0]+p[n][k][1]);
		}
	}

}
