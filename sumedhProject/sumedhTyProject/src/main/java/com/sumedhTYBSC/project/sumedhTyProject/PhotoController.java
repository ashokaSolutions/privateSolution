package com.sumedhTYBSC.project.sumedhTyProject;

import org.springframework.data.relational.core.sql.In;
import org.springframework.http.HttpStatus;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RestController;
import org.springframework.web.server.ResponseStatusException;

import java.util.ArrayList;
import java.util.*;

@RestController
public class PhotoController {
//YOU CANNOT ADD LIST OUTSIDE PSVMM SO USE "LIST.OF"
    //private List<Photo> db=List.of(new Photo("1","text.jpg"),new Photo("2","hello.png"));

    private Map<String,Photo> db=new HashMap<>(){
        {
            put("1",new Photo("1","fuvk.jpg"));
        }
        {
            put("2",new Photo("2","ok.png"));
        }
    };
    @GetMapping("/")
    public String hello(){
        return "hello there";
    }

    //all pics
    @GetMapping("/photo")
    public Map<String,Photo> get(){
        return db;
    }

    //one specific file
    @GetMapping("/photo/{id}")
    public Photo get(@PathVariable String id){
        Photo pic=db.get(id);
        if(pic==null) {
            //this will thow not found exception and code will stop there and will not reach return
            throw new ResponseStatusException(HttpStatus.NOT_FOUND);
        }
        return pic;
    }
}
/*
    Getmapping gets the page entered
 */