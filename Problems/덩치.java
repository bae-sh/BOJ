import java.util.*;
public class 덩치 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int x[]=new int[n];
		int y[]=new int[n];
		int z[]=new int[n];
		for(int i=0;i<n;i++) {
			x[i]=sc.nextInt();
			y[i]=sc.nextInt();
			z[i]=1;
		}
		
		for(int i=0;i<n;i++) {
			for(int j=i+1;j<n;j++) {
				if(x[i]>x[j]&&y[i]>y[j]) {
					z[j]++;
				}else if(x[i]<x[j]&&y[i]<y[j]) {
					z[i]++;
				}
			}
		}
		for(int i:z) {
			System.out.print(i+" ");
		}
		
	}

}

