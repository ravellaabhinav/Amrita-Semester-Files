/*
Write a java program for to solve printer synchronization problem in which all the jobs must be completed in order.
*/

 
 import java.util.concurrent.ExecutorService;
 import java.util.concurrent.Executors;
 
 public class oddeven {
 	public static void main(String[] args) {
 		ExecutorService executor = Executors.newFixedThreadPool(3);
 		executor.execute(new Printer1());
 		executor.execute(new Printer2());
 		executor.execute(new Printer3());
 		executor.shutdown();
	}
 }
 
 class Printer1 implements Runnable {
 	@Override
 	public void run() {
 		System.out.println("Printer 1");
 	}
 }
 
 class Printer2 implements Runnable {
 	@Override
 	public void run() {
 		System.out.println("Printer 2");
 	}
 }
 
 class Printer3 implements Runnable {
 	@Override
 	public void run() {
 		System.out.println("Printer 3");
 	}
 }
 
