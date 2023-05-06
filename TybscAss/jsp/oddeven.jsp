<html>
	<body>
	   <form action="oddeven.jsp" method="post">
		<input type="number" name="num"/>
		<input type="submit" name="submit" >
	    </form>
		
		<%@ page language="java" %>
		<%
				
				String num=request.getParameter("num");
				
				if(num==null){
					out.println("variable not set");
				}
				else{
					int n=Integer.parseInt(num);
					if(n%2==0){
						out.print(n+" is even");
					}else{
						out.print(n+" is odd");
					}
				}
			
		%>
	</body>
</html>
