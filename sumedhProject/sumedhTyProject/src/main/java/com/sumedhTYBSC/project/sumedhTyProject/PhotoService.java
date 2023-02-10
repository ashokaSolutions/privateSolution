package com.sumedhTYBSC.project.sumedhTyProject;


import org.springframework.stereotype.Controller;

import java.util.Collection;
import java.util.HashMap;
import java.util.Map;

@Controller
public class PhotoService {
    private Map<String,Photo> db=new HashMap<>(){
        {
            put("1",new Photo("1","fuvk.jpg"));
        }
        {
            put("2",new Photo("2","ok.png"));
        }
    };

    public Collection<Photo> gets(){
        return  db.values();
    }
    public Photo get(String id) {
        return db.get(id);
    }
}
