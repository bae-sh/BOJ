import java.util.*;
public class 카드게임 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int d[][]=new int[2][10];
		int a=0;
		int b=0;
		for(int i=0;i<2;i++) {
			for(int j=0;j<10;j++) {
				d[i][j]=sc.nextInt();
			}
		}
		for(int i=0;i<10;i++) {
			if(d[0][i]>d[1][i]) {
				a++;
			}else if(d[0][i]<d[1][i]) {
				b++;
			}
		}
		if(a>b)
			System.out.println("A");
		else if(a<b)
			System.out.println("B");
		else
			System.out.println("D");
	}

}
