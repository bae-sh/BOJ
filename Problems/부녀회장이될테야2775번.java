package 백준;
import java.util.*;
public class 부녀회장이될테야2775번 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int d[][]=new int[15][15];
		int n=sc.nextInt();
		for(int i=0;i<15;i++) {
			d[0][i]=i;
		}
		for(int i=1;i<15;i++) {
			for(int j=1;j<15;j++) {
				d[i][j]=d[i][j-1]+d[i-1][j];
			}
		}
		for(int i=0;i<n;i++) {
			int a=sc.nextInt();
			int b=sc.nextInt();
			System.out.println(d[a][b]);
		}
	}

}
