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

	//Variaveis

	$scope.cores = [
		{name : 'Preto'},
		{name : 'Marrom'},
		{name : 'Havana'},
		{name : 'Ouro'},
		{name : 'Areia'},
		{name : 'Verde-Oliva'},
		{name : 'Búfalo Castor'},
		{name : 'Búfalo Café'}
	];

	$scope.solados = [
		{name : 'Preto'},
		{name : 'Marrom'}
	];
	
	$scope.formas = [
		{name : 'Normal'},
		{name : 'Cowboy'},
		{name : 'Segurança'}
	];
	
	$scope.vendedores = [
		{name : 'Maria Aparecida'},
		{name : 'João Paulo'},
		{name : 'José Ricardo'}
	];

	$scope.fechamentos = [
		{name : 'Elástico'},
		{name : 'Elástico Tapado'},
		{name : 'Zíper'}
	];

	$scope.palmilhas = [
		{name : 'Comum'},
		{name : 'Sola'}
	];
	
	$scope.tipos = [
		{name : 'Botina'},
		{name : 'Sapato'}
	];
	
	$scope.itens = [
		{name : 'Cores'},
		{name : 'Solados'},
		{name : 'Formas'},
		{name : 'Vendedores'},
		{name : 'Fechamentos'},
		{name : 'Palmilhas'},
		{name : 'Tipos'}
	];
});