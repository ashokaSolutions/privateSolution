<html>
<body>
		<%
			int num=Integer.parseInt(request.getParameter("num"));
			int i=2;
			int flag=0;
			while(i<num){
				if(num%i==0){
					flag=1;
					break;
				}else{
					i++;
				}
			}
			if(flag==1){
		%>
			<h2>this is not prime</h2>
		<%}else{%>
			<h2>this is prime</h2>
		<%}%>
</body>
</html>
