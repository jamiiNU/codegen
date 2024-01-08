// chip content
NUTOOL_PER.g_cfg_chips = [
	{ name: "NUC122ZD2AN", pkg: "QFN33" , type: "typeA" },
	{ name: "NUC122ZC1AN", pkg: "QFN33" , type: "typeA" },
	{ name: "NUC122LD2AN", pkg: "LQFP48" },
];

NUTOOL_PER.g_cfg_unusedPerFunctions = {
	// "M252_C": {
		// "ALL": ["BPWM"],
		// "PARTIAL": ["PDMA_CH5", "PDMA_CH6", "PDMA_CH7"],
	// },
	// "M251FB2AE": {
		// "PARTIAL": ["USBD"],
	// },
}

// relative to the location of the directory containing tags
NUTOOL_PER.g_cfg_projectLoaction = "\\NuCodeGen";
NUTOOL_PER.g_cfg_thidrPartyLibLoaction = "";
NUTOOL_PER.g_cfg_thirdPartyLibs = [];
// if you want to dynamically load .txt files, keep this array empty.
NUTOOL_PER.g_cfg_perFunctions = [
'DemoUIChangeEvent.txt',
'DemoUICheckboxBooleanDependencies.txt',
'DemoUICheckboxDependencies.txt',
// 'DemoUICheckPinClock.txt',
'DemoUICheckPinClockPeripheral',
'DemoUIFieldFromFilter.txt',
'DemoUIGroup.txt',
'DemoUIHexText.txt',
'DemoUIHexTextDependencies.txt',
'DemoUIHiddenAndObservable.txt',
'DemoUIIntegerDependencies.txt',
'DemoUIMultiSelect.txt',
'DemoUIMultiSelectObservable.txt',
'DemoUIRadioDependencies.txt',
'DemoUISelectDependencies.txt',
'DemoUITagsFilterOut.txt',
'DemoUITextOnly.txt',
'DemoUITwoToOneDependencies.txt',
'LAYOUT_OneRow.txt',
'LAYOUT_TwoRows.txt',
// 'Test.txt',
// 'TestDependencies.txt',
// 'TestDependenciesWithGroup.txt',
// 'TestGroup.txt',
// 'TestObservable.txt',
// 'TestObservableWithGroup.txt',
// 'TestValidation.txt',
'UART_AutoFlow.txt',
'UART_TxRXFunction.txt',
];
