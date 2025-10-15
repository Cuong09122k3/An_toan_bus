// ========== ANDROID JAVA CODE ==========
private void registerUser(String email, String password) {
    auth.createUserWithEmailAndPassword(email, password)
        .addOnCompleteListener(new OnCompleteListener<AuthResult>() {
            @Override
            public void onComplete(@NonNull Task<AuthResult> task) {
                if (task.isSuccessful()) {
                    Toast.makeText(RegisterActivity.this, "Tạo tài khoản thành công.", Toast.LENGTH_SHORT).show();
                    Intent intent = new Intent(getApplicationContext(), PeoDisplayActivity.class);
                    startActivity(intent);
                    finish();
                } else {
                    Toast.makeText(RegisterActivity.this, "Tạo tài khoản thất bại.", Toast.LENGTH_SHORT).show();
                }
            }
        });
}

private void loginUser(String email, String password) {
    auth.signInWithEmailAndPassword(email, password)
        .addOnCompleteListener(new OnCompleteListener<AuthResult>() {
            @Override
            public void onComplete(@NonNull Task<AuthResult> task) {
                if (task.isSuccessful()) {
                    Toast.makeText(LoginActivity.this, "Đăng nhập thành công.", Toast.LENGTH_SHORT).show();
                    Intent intent = new Intent(getApplicationContext(), PeoDisplayActivity.class);
                    startActivity(intent);
                    finish();
                } else {
                    Toast.makeText(LoginActivity.this, "Email hoặc mật khẩu không chính xác.", Toast.LENGTH_SHORT).show();
                }
            }
        });
}

private void readDatabaseN(TextView display_data, String child, String parent) {
    FirebaseDatabase database = FirebaseDatabase.getInstance();
    DatabaseReference myRef = database.getReference(parent).child(child);
    myRef.addValueEventListener(new ValueEventListener() {
        @Override
        public void onDataChange(@NonNull DataSnapshot dataSnapshot) {
            Integer value = dataSnapshot.getValue(Integer.class);
            display_data.setText(String.valueOf(value));
        }
        @Override
        public void onCancelled(@NonNull DatabaseError error) {
        }
    });
}
