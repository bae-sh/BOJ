import java.util.*;
public class 구슬탈출2 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int m=sc.nextInt();
		int x,y;
		int x1=0,y1=0,x2 = 0,y2=0;
		String d[][]=new String[n][m];
		ArrayList<Pair13460> ar=new ArrayList();//0일때 red 1일때 blue
		for(int i=0;i<n;i++) {
			String s[]=sc.nextLine().split("");
			for(int j=0;j<m;j++) {
				d[i][j]=s[j];
				if(d[i][j].equals("O")) {
					x=i;y=j;
				}else if(d[i][j].equals("R")) {
					x1=i;y1=j;
				}else if(d[i][j].equals("B")) {
					x2=i;y2=j;
				}
			}
			ar.add(new Pair13460(x1, y1, x2, y2));
		}
		
	}
	public static void go(String d[][],ArrayList<Pair13460> ar) {
		
	}

}
class Pair13460{
	int x1,y1,x2,y2;
	public Pair13460(int x1,int y1,int x2,int y2) {
		this.x1=x1;
		this.y1=y1;
		this.x2=x2;
		this.y2=y2;
	}
	
}
