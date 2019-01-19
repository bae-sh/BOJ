package 백준;
import java.util.*;
public class 빗물 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int h=sc.nextInt();
		int w=sc.nextInt();
		int d[][]=new int[w][h];
		for(int i=0;i<w;i++) {
			int a=sc.nextInt();
			for(int j=1;j<=a;j++) {
				d[h-j][i]++;
			}
		}
	}

}
