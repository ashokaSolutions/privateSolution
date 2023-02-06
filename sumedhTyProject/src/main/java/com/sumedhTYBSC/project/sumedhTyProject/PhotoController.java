package com.sumedhTYBSC.project.sumedhTyProject;

import jakarta.validation.Valid;
import org.springframework.data.relational.core.sql.In;
import org.springframework.http.HttpStatus;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.multipart.MultipartFile;
import org.springframework.web.server.ResponseStatusException;

import java.io.IOException;
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

    //we can use deleteMapping also but i didnt understood it so used this type instead
    @GetMapping("/photo/delete/{id}")
    public void delete(@PathVariable String id){
        Photo pic=db.remove(id);
        if(pic==null) {
            //this will thow not found exception and code will stop there and will not reach return
            throw new ResponseStatusException(HttpStatus.NOT_FOUND);
        }

    }

    //sending json and we need to put file so we will req file

    @PostMapping("/photo")
    public Photo create(@RequestPart("data") @Valid MultipartFile file) throws IOException {
        Photo pic =new Photo();
        pic.setData(file.getBytes());
        pic.setFileName(file.getOriginalFilename());
        pic.setId(UUID.randomUUID().toString());
        db.put(pic.getId(),pic);
        return pic;
    }
}
/*
    Getmapping gets the page entered
 */