var app = angular.module('app', []);

app.controller("mainCtrl", function($scope) {
   
	currentPage     = 'calcados';
	currentSection  = 'calcados';

	$scope.isPage = function (page){
		return page == currentPage;
	};

	$scope.isSection = function (section){
		return section == currentSection;
	};

	$scope.setPage = function (page){
		currentPage    = page;
	};

	$scope.setSection = function (section){
		currentSection = section;
	}

});