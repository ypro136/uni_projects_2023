<?php 
    include('db_connection.php');
    $error = $email = $password = '';
    // $username = $_GET['username'];

    if(isset($_GET['submit'])){
    }
?>

<!DOCTYPE html>
<html lang="en">
	<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/materialize/1.0.0/css/materialize.min.css"> <!-- Framework -->
	<?php include('Template/Header.php'); ?>

    <h4 class="center grey-text">Welcome <?php echo $username ?>!</h4>

		<form class="white" action="add.php" method="POST">
			<h4 class="center">Product Details</h4>
			
			<label>Product Name</label>
			<input type="text" name="name" value="">
			<div class="red-text"></div>

			<label>Price</label>
			<input type="text" name="price" value="">
			<div class="red-text"></div>

			<label>Category</label>
			<input type="text" name="category" value = "">
			<div class="red-text"></div>
			
				<div class="center">
					<div class="form-group">
						<button type="submit" name="submit" >Add</button>
					</div>
				</div>
		</form>

		<h4 class="center">Your Products</h4>
		<form class="white" style="width: 800px;" action="">
			<div>
				<label style="color: black; font-size: 17px;">Product</label>
				<label class="center-text" style="color: black; font-size: 17px;">Price</label>
			</div>
		</form>
		
	</body>
</html>
