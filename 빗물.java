import java.util.*;
public class 빗물 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int h=sc.nextInt();
		int w=sc.nextInt();
		int a[][]=new int[h][w];
		int ans=0;
		for(int i=0;i<w;i++) {
			int x=sc.nextInt();
			for(int j=h-1;j>=h-x;j--) {
				a[j][i]=1;
			}
		}
		for(int i=0;i<h;i++) {
			int right=-1;
			int left=-1;
			for(int j=0;j<w;j++) {
				if(a[i][j]==1) {
					if(left==-1) {
						left=j;
					}else {
						right=j;
						ans+=right-left-1;
						left=right;
					}
				}
			}
		}
		System.out.println(ans);
		
	}

}
