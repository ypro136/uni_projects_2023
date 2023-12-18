<?php 
    include('db_connection.php');
    $error = $email = $password = '';
    
    if(isset($_GET['submit'])){
        $email = mysqli_real_escape_string($conn, $_GET['email']);   //escaping any user harm or malicious code.
        $password = mysqli_real_escape_string($conn, $_GET['password']);

        $sql = "SELECT * FROM user_accounts WHERE email = '$email' AND password = '$password'";
        
        $result = mysqli_query($conn, $sql);
        $user = mysqli_fetch_assoc($result);

        if(!isset($user)){
            $error='Email or Password is incorrect';

            $email = $_GET['email'];
            $password = $_GET['password'];
        }

        mysqli_free_result($result);
        mysqli_close($conn);
        
        if($error == '')
           header("Location: {$user['user_type']}.php?username={$user['username']} & id={$user['ID']}");
    }
?>

<!DOCTYPE html>
<html lang="en">
    <?php include('Template/Header.php'); ?>

    <div class="login-container CENTERABS">
        <h2>Login</h2>
        <div style="color: red; display: inline;"><?php echo $error ?></div>
        
        <form action="index.php" method="GET">
            <div class="form-group">
                <label for="email">Email:</label>
                <!-- <input type="email" name="email" required> -->
                <input type="email" name="email" placeholder="example@gmail.com" value= <?php echo $email ?>>
            </div>

            <div class="form-group">
                <label for="password">Password:</label>
                <!-- <input type="password" name="password" required> -->
                <input type="password" name="password" placeholder="Your Password" value= <?php echo $password ?>>
            </div>

            <div class="form-group">
                <button type="submit" name="submit" >Login</button>
            </div>
            
            <p class="grey">
                Don’t have an account yet? 
                <a href="SignUp.php" style="color: #1A8FE3;text-decoration: none;">Sign Up</a>
            </p>
        </form>
    </div>
    
    <?php include('Template/Footer.php'); ?>
</html>
