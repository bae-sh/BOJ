import java.util.*;
import java.io.*;
public class 수정렬하기4 {

	public static void main(String[] args) throws IOException{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		int x[] = new int[n];
		StringBuilder sb=new StringBuilder();
		for(int i=0;i<n;i++) {
			x[i]=Integer.parseInt(br.readLine());
		}
		sort(x,0,x.length-1);
		for(int i=n-1;i>=0;i--) {
		sb.append(x[i]+"\n");}
		System.out.println(sb.toString());
	}
	public static void sort(int data[],int l,int r) {
		int left = l;
		int right = r;
		int pivot = data[(l+r)/2];
		
		do {
			while(data[left]<pivot) left++;
			while(data[right]>pivot) right--;
			if(left<=right) {
				int temp = data[left];
				data[left]=data[right];
				data[right]=temp;
				left++;
				right--;
			}
		}while(left<=right);
		if(l<right) sort(data,l,right);
		if(r>left) sort(data,left,r);
	}
}