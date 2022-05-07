package com.abdallah;

import java.text.DecimalFormat;

class Calculations {
    public static float avg = 0;
    public static float sum = 0;

    synchronized public void average(int[] arr) {
        for (int i = 0; i < arr.length; i++) {
            sum += arr[i];
        }
        avg = sum / arr.length;
    }

    public static int min = Integer.MAX_VALUE;

    synchronized public void minimum(int[] arr) {
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] < min) {
                min = arr[i];
            }
        }
    }

    public static int max = Integer.MIN_VALUE;

    synchronized public void maximum(int[] arr) {
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] > max) {
                max = arr[i];
            }
        }
    }

    public static int mid = 0;

    synchronized public void median(int[] arr) {
        int temp = 0;
        for (int i = 0; i < arr.length - 1; i++) {
            for (int j = 0; j < arr.length - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }

        mid = arr[arr.length / 2];


    }

    public static double stanDev = 0.0;
    public static double res = 0.0;
    public static double sq = 0.0;

    synchronized public void standardDev(int[] arr){
        int n = arr.length;

        for(int i = 0; i < n; i++){
            stanDev = stanDev + Math.pow((arr[i] - avg), 2);
        }

        sq = stanDev / n;
        res = Math.sqrt(sq);
        DecimalFormat format = new DecimalFormat("0.00");
    }


}

class ThreadAverage extends Thread{
    Calculations x;
    int[] Array;
    public ThreadAverage(Calculations y, int[] arr){
        x = y;
        Array = arr;
    }
    public void run() {
        x.average(Array);
    }
}


class ThreadMin extends Thread{
    Calculations x;
    int[] Array;
    public ThreadMin(Calculations y, int[] arr){
        x = y;
        Array = arr;
    }

    public void run(){
        x.minimum(Array);
    }
}

class ThreadMax extends Thread {
    Calculations x;
    int[] Array;
    public ThreadMax(Calculations y, int[] arr){
        x = y;
        Array = arr;
    }

    public void run(){
        x.maximum(Array);
    }
}


class ThreadMedian extends Thread {
    Calculations x;
    int[] Array;
    public ThreadMedian(Calculations y, int[] arr){
        x = y;
        Array = arr;
    }

    public void run(){
        x.median(Array);
    }
}

class ThreadStanDev extends Thread{
    Calculations x;
    int[] Array;
    public ThreadStanDev(Calculations y, int[] arr){
        x = y;
        Array = arr;
    }

    public void run(){
        x.standardDev(Array);
    }
}

public class Main {

    public static void main(String[] args) {

        if (args.length < 1){
            System.out.println("No arguments inputted");
            return;
        }

        int[] a = new int[args.length];
        for(int i = 0; i < args.length; i++){
            a[i] = Integer.parseInt(args[i]);
        }

        Calculations avg = new Calculations();
        Calculations min = new Calculations();
        Calculations max = new Calculations();
        Calculations median = new Calculations();
        Calculations stanDev = new Calculations();
        ThreadAverage t1 = new ThreadAverage(avg, a);
        ThreadMin t2 = new ThreadMin(min, a);
        ThreadMax t3 = new ThreadMax(max, a);
        ThreadMedian t4 = new ThreadMedian(median, a);
        ThreadStanDev t5 = new ThreadStanDev(stanDev, a);
        t1.start();
        t2.start();
        t3.start();
        t4.start();
        try{
            t1.join();
        } catch(InterruptedException e){
            System.out.println(e);
        }
        t5.start();
        try {
            t2.join();
            t3.join();
            t4.join();
            t5.join();
        }catch(InterruptedException e){
            System.out.println(e);
        }
        DecimalFormat format = new DecimalFormat("0.00");
        System.out.println("The average value is " + format.format(Calculations.avg));
        System.out.println("The minimum value is " + Calculations.min);
        System.out.println("The maximum value is " + Calculations.max);
        System.out.println("The median value is " + Calculations.mid);
        System.out.println("The standard deviation value is " + format.format(Calculations.res));
    }
}
