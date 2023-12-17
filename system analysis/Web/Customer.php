<?php 
    include('db_connection.php');
    if(isset($_POST['buy'])){
        $id = mysqli_real_escape_string($conn, $_POST['product_to_delete']);
        $sql = "DELETE FROM products WHERE ID = $id";
        mysqli_query($conn, $sql);
    }
	
	$sql = 'SELECT * FROM products';

	$result = mysqli_query($conn, $sql);

	$products = mysqli_fetch_all($result, MYSQLI_ASSOC);

	mysqli_free_result($result);

	mysqli_close($conn);
    
?>

<!DOCTYPE html>
<html lang="en">
    <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/materialize/1.0.0/css/materialize.min.css"> <!-- Framework -->
    <?php include('Template/Header.php'); ?>

    <!-- <h4 class="center grey-text">Welcome <?php echo $username ?>!</h4> -->
    <h4 class="center grey-text">Welcome!</h4>

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
                            <h6 class="left-align">Selled By: <?php echo $product['seller_name']?></h6>
                        
                            <!-- <div class="center form-group">
                                <a class="brand-text" href="customer.php?id=<?php echo $product['ID']?>">Buy</a>
                            </div> -->


                            <form action="customer.php" method="POST"class="center form-group">
                                <input type="hidden" name="product_to_delete" value = "<?php echo $product['ID'] ?>">
                                <button type="submit" name="buy" style="
                                    background-color: orange; 
                                    color: black;
                                    width: 200px;
                                    font-size: 17px;
                                ">Buy</button>
                            </form>
                        </div>
                    </div>
                </div>
            <?php endforeach; ?>
		</div>
	</div>

	
    </body>
</html>