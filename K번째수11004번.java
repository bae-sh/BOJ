package 백준;

import java.util.*;
import java.io.*;
public class K번째수11004번 {

	public static void main(String[] args) throws IOException{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		String[] st=br.readLine().split(" ");
		int n=Integer.parseInt(st[0]);
		int k=Integer.parseInt(st[1]);
		ArrayList<Integer> a=new ArrayList<>();
		st=br.readLine().split(" ");
		for(int i=0;i<n;i++) {
			a.add(Integer.parseInt(st[i]));
		}
		System.out.println(quick_selection(a, k));
	}
	public static int quick_selection(ArrayList<Integer> arr,int kth) {
		int pivot=arr.get(arr.size()/2);
		ArrayList<Integer> left=new ArrayList<>();
		ArrayList<Integer> mid=new ArrayList<>();
		ArrayList<Integer> right=new ArrayList<>();
		for(int i:arr) {
			if(i<pivot) 
				left.add(i);
			else if(i>pivot) 
				right.add(i);
			else 
				mid.add(i);
			}
			if(kth<=left.size()) {
				return quick_selection(left, kth);
			}
			else if(kth<=left.size()+mid.size()) {
				return mid.get(0);
			}
			else {
				return quick_selection(right, kth-left.size()-mid.size());
			}
		
	}
}
