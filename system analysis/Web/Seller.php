<?php 
  include('db_connection.php');
  $username = $_GET['username'];
  $id = $_GET['id'];
	
	if(isset($_POST['submit'])){
		$sql = "INSERT INTO products(seller_id, seller_name, name, price, category) VALUES('{$id}', '{$username}', '{$_POST['name']}','{$_POST['price']}', '{$_POST['category']}')";
		mysqli_query($conn, $sql);
	}

	if(isset($_POST['delete'])){
		$productid = mysqli_real_escape_string($conn, $_POST['product_to_delete']);
		$sql = "DELETE FROM products WHERE product_id = $productid";
		mysqli_query($conn, $sql);
	}

	$sql = "SELECT * FROM products";

	$result = mysqli_query($conn, $sql);

	$products = mysqli_fetch_all($result, MYSQLI_ASSOC);

	mysqli_free_result($result);

	mysqli_close($conn);
?>

<!DOCTYPE html>
<html lang="en">
	<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/materialize/1.0.0/css/materialize.min.css"> <!-- Framework -->
	<?php include('Template/Header.php'); ?>

    <h4 class="center grey-text">Welcome <?php echo $username ?>!</h4>

		<form class="white" action="Seller.php?username=<?php echo $username ?> & id=<?php echo $id ?>" method="POST" style="
				width: 500px;
				margin: 20px auto;
				padding: 20px;">
			<h4 class="center">Product Details</h4>
			
			<label>Product Name</label>
			<input type="text" name="name" value="" required>
			<div class="red-text"></div>

			<label>Price</label>
			<input type="text" name="price" value="" required>
			<div class="red-text"></div>

			<label>Category</label>
			<input type="text" name="category" value = "" required>
			<div class="red-text"></div>
			
				<div class="center">
					<div class="form-group">
						<button type="submit" name="submit" >Add</button>
					</div>
				</div>
		</form>

		<h4 class="center">Your Products</h4>
		<div class="container">
				<div class="row">
					<?php foreach($products as $product): ?>
							<div class="col s3 md3">
									<div class="card z-depth-0">
											<div class="card-content center">
													<h5><?php echo htmlspecialchars($product['name']);?></h5>
													
													<div class="right-align">
															<h6>Price: <?php echo $product['price']?></h6>
													</div>
											</div>

											<div class="card-action right-align form-group">
													<h6 class="left-align">Category: <?php echo $product['category']?></h6>

													<form action="Seller.php?username=<?php echo $username ?> & id=<?php echo $id ?>" method="POST"class="center form-group">
															<input type="hidden" name="product_to_delete" value = "<?php echo $product['product_id'] ?>">
															<button type="submit" name="delete" style="
																	margin-top: 10px;
																	background-color: Red; 
																	color: white;
																	width: 200px;
																	font-size: 17px;
															">Delete</button>
													</form>
												</div>
											</div>
										</div>
            <?php endforeach; ?>
				</div>
			</div>



		<!-- <h4 class="center">Your Products</h4>
		<form class="white" style="width: 800px;" action="">
			<div>
				<label style="color: black; font-size: 17px;">Product</label>
				<label class="center-text" style="color: black; font-size: 17px;">Price</label>
			</div>
		</form> -->
		
	</body>
</html>
