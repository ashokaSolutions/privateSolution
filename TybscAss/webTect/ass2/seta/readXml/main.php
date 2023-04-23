<html>
    <head>
        <style>
            #ItemName {
                Color : red;
                Font-family : copperplate Gothic Light;
                Font-size : 16pt;
                Font :bold;
            }
            #ItemPrice, #Quantity{
                color:yellow;
                font-family:Arial;
                font-size:12 pt;
                font:bold;
            }
        </style>
    </head>
    <body>
        <?php
            $xml=simplexml_load_file("item.xml");
             foreach($xml->Item as $item){
                echo "<p id='ItemName'>".$item->ItemName."</p>";
                echo "<p id='ItemPrice'>".$item->ItemPrice."</p>";
                echo "<p id='Quantity'>".$item->Quantity."</p>";
             }     
        ?>   
    </body>
</html>
