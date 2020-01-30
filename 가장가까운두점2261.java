import java.util.*;

public class 가장가까운두점2261 {
	static int length=-1;
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		Pair2261[] p=new Pair2261[n];
		for(int i=0;i<n;i++) {
			int x=sc.nextInt();
			int y=sc.nextInt();
			p[i]=new Pair2261(x, y);
		}
		Arrays.sort(p);
		
		System.out.println(sort(0,n-1,p));
	}
	static int Find(int start,int end,Pair2261[] p) {
		if(start==end)
			return 2100000000;
		else if(end-start==1) {
			return sq(p[start].x,p[start].y,p[end].x,p[end].y);
		}else {
			return sort(start,end,p);
		}
	}
	static int midFind(int start,int end,int len,Pair2261[] p) {
		int mid= (end+start)/2;
		int start1=mid;
		int end1=mid;
		for(int i=start;i<mid;i++) {
			if(p[mid].x-p[i].x<=len) {
				start1=i;
				break;
			}
		}
		for(int i=end;i>mid;i--) {
			if(p[i].x-p[mid].x<=len) {
				end1=i;
				break;
			}
		}
		Pair2261[] p2=new Pair2261[end1-start1+1];
		for(int i=0;i<=end1-start1;i++) {
			int x=p[start1+i].x;
			int y=p[start1+i].y;
			p2[i]=new Pair2261(y, x);
		}
		Arrays.sort(p2);
		
		for(int i=0;i<end1-start1+1;i++) {
			if(i+6<=end1-start1) {
				for(int j=i+1;j<i+6;j++) {
					len=Math.min(len, sq(p2[i].x,p2[i].y,p2[j].x,p2[j].y));
				}
			}else {
				for(int j=i+1;j<end1-start1+1;j++) {
					len=Math.min(len, sq(p2[i].x,p2[i].y,p2[j].x,p2[j].y));
				}
			}
		}
		return len;
	}
	static int sort(int start,int end,Pair2261[] p) {
		int left=Find(start,(end+start)/2,p);
		int right=Find((end+start)/2,end,p);
		int len=Math.min(left, right);
		
		return midFind(start,end,len,p);
	}
	static int sq(int x1,int y1,int x2,int y2) {
		return (int)(Math.pow(x2-x1, 2)) +(int)(Math.pow(y2-y1, 2));
	}

}

class Pair2261 implements Comparable<Pair2261> {
	int x, y;

	public Pair2261(int x, int y) {
		this.x = x;
		this.y = y;
	}
	@Override
	public int compareTo(Pair2261 o) {
		if (this.x > o.x) {
			return 1;
		} else if (this.x == o.x) {
			return 0;
		} else {
			return -1;
		}
	}

}
