package com.AxRACE_Lap_Timer;

import android.content.Context;
import android.support.annotation.NonNull;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.TextView;

import com.timerapp.mxlaptimer.R;

import java.util.ArrayList;

/**
 * Created by User on 3/14/2017.
 */

public class PersonListAdapter extends ArrayAdapter<Rider> {

    private static final String TAG = "PersonListAdapter";

    private Context mContext;
    private int mResource;


    /**
     * Default constructor for the PersonListAdapter
     * @param context
     * @param resource
     * @param objects
     */
    public PersonListAdapter(Context context, int resource, ArrayList<Rider> objects) {
        super(context, resource, objects);
        mContext = context;
        mResource = resource;
    }

    @NonNull
    @Override
    public View getView(int position, View convertView, ViewGroup parent) {
        //get the persons information
        int pos = getItem(position).getPos();
        String name = getItem(position).getName();
        String time = getItem(position).getTime();
        String difftime = getItem(position).getDifftime();
        int riderScore = getItem(position).getScore();
        int riderNumber = getItem(position).getNumber();

        //Create the person object with the information
        Rider person = new Rider(pos,name,time,difftime,riderScore,riderNumber);

            LayoutInflater inflater = LayoutInflater.from(mContext);
            convertView = inflater.inflate(mResource, parent, false);
            TextView tvPos = (TextView) convertView.findViewById(R.id.textView1);
            TextView tvName = (TextView) convertView.findViewById(R.id.textView2);
            TextView tvTime = (TextView) convertView.findViewById(R.id.textView3);
            TextView tvDifftime = (TextView) convertView.findViewById(R.id.textView4);

        tvPos.setText(Integer.toString(person.getPos()));
        tvName.setText(person.getName());
        tvTime.setText(person.getTime());
        tvDifftime.setText(person.getDifftime());

        return convertView;
    }
}

























