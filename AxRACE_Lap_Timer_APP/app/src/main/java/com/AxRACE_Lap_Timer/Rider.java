package com.AxRACE_Lap_Timer;

/**
 * Created by User on 3/14/2017.
 */

public class Rider {
    private int pos;
    private String name;
    private String time;
    private String difftime;
    private int riderScore;
    private int riderNumber;



    public Rider(int pos, String name,  String time,  String difftime, int riderScore, int riderNumber ) {
        this.name = name;
        this.pos = pos;
        this.time = time;
        this.difftime = difftime;
        this.riderScore = riderScore;
        this.riderNumber = riderNumber;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getPos() {
        return pos;
    }

    public void setPos(int pos) {
        this.pos = pos;
    }

    public String getTime() {
        return time;
    }

    public void setTime(String time) {
        this.time = time;
    }

    public String getDifftime() {
        return difftime;
    }

    public void setDifftime(String difftime) {
        this.difftime = difftime;
    }

    public int getScore() {
        return riderScore;
    }
    public void setriderScore(int riderScore) {
        this.riderScore = riderScore;
    }

    public int getNumber() {
        return riderNumber;
    }
    public void setriderNumber(int riderNumber) {
        this.riderNumber = riderNumber;
    }
}


