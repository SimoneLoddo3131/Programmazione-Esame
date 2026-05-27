#include <iostream>
#include <Eigen/Dense>
#include <Eigen/SVD>
double condA(const Eigen::MatrixXd& A)
{
  Eigen::JacobiSVD<Eigen::MatrixXd> svd(A);
  Eigen::VectorXd singularValuesA = svd.singularValues();
  return singularValuesA.maxCoeff() / singularValuesA.minCoeff();
}

int main(){
	
	const double  tol= 1.0e-15;
	unsigned int n = 67;
	
	  Eigen::MatrixXd B = Eigen::MatrixXd::Random(n, n);
	   if (abs(B.determinant()) < tol)
    return -1;
	   Eigen::MatrixXd A = B.transpose() * B;
  Eigen::VectorXd x_one = Eigen::VectorXd::Ones(n);

  Eigen::VectorXd b = A * x_one;

  Eigen::VectorXd xk = Eigen::VectorXd::Zero(n);
Eigen::VectorXd res = b - A * xk;
  double res_norm_0 = res.norm();
	 unsigned int it = 0;
  const double res_tol = 1.0e-12;
  const unsigned int it_max = 10000;
  
  
  
  auto p0=res;
  auto pk=p0;
  while(it<it_max &&  res.norm() > res_tol * res_norm_0 ){
	  const double alfak=(pk.transpose()*res).value()/(pk.transpose()*A*pk).value();
	 xk=xk+alfak*pk;
	 Eigen::VectorXd res_next = b - A * xk;
	 
	 const auto beta= (pk.transpose()*A*res_next).value()/(pk.transpose()*A*pk).value();
	 pk=res_next-beta*pk;
	 res=res_next;
	 it++;
	  
  }
  const auto err_rel = (x_one.norm()==0)? (xk - x_one).norm() :
                                              (xk - x_one).norm() / x_one.norm();
	
	 std::cout.precision(4);
  std::cout<< std::scientific<< "it"<< "/"<< "it_max"<< std::endl;
  std::cout<< std::scientific<< it<< "/"<< it_max<< std::endl;
  std::cout<< std::scientific<< "res"<< "/"<< "res_tol"<< std::endl;
  std::cout<< std::scientific<< res.norm() / res_norm_0<< "/"<< res_tol<< std::endl;
  std::cout<< std::scientific<< "err_rel"<< std::endl;
  std::cout<< std::scientific<< err_rel<< std::endl;
  std::cout<< std::scientific<< "soluzione"<< std::endl;
  std::cout<< std::scientific<< xk << std::endl;
	
	

	
	
	
	
	
	
	
	
}