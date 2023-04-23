<html>
    <body>
        <?php   
            $xml=new DomDocument();
            $xml->load("movie.xml");
            foreach($xml->getElementsByTagName("MovieInfo") as $data){
                //[0] is for the within tags and is 0 only
                $no=$data->getElementsByTagName("MovieNo")[0]->nodeValue;
                $title=$data->getElementsByTagName("MovieTitle")[0]->nodeValue;
                $name=$data->getElementsByTagName("ActorName")[0]->nodeValue;
                $year=$data->getElementsByTagName("ReleaseYear")[0]->nodeValue;
                
                echo "<hr>";
                echo "$no <br>";
                echo "$title <br>";
                echo "$name <br>";
                echo "$year <br>";  
            }
        ?>
    </body>
</html>
