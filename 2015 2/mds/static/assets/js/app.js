var app = angular.module('app', []);

app.controller("mainCtrl", function($scope) {
   
	currentPage = 'pedidos';

	$scope.isPage = function (page){
		return page == currentPage;
	};

	$scope.setPage = function (page){
		currentPage = page;
	};


});