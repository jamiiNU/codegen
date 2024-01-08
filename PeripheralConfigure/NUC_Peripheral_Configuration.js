// main code of NuTool - IpConfigure
// the sole global variable denoted by capital letters
var NUTOOL_PER = {};

(function () {
	// all the global variables within the immediately-invoked function scope
	var g_bLessThanOrEqualIE8,
		g_unPrintedCharacters,
		g_utility = {
			getContext: null,
			removeContext: null,
			addEvent: null,
			triggerEvent: null
		},
		g_NUC_TreeView_Width = 0,
		g_Dialog_Width,
		g_Dialog_Height,
		g_chipTypes = ["M251", "M253", "M031", "NUC100"],
		g_chipTypesDeveloping = ["M030G", "DEMO"],
		g_chipType = "",
		g_updatedSnippetFile = "",
		g_selectedPartNoValue = "",
		g_partNumber_package = "",
		g_partNumber_type = "",
		g_supportedGPIOPins = {},
		g_userHeader = "",
		g_generatedCodeFromPerString = "",
		g_enabledThirdPartyLibString = "",
		g_enabledPeripheralFunctionString = "",
		g_currentSnippetFilePath = "",
		g_currentSnippetLayoutath = "",
		g_lastCheckedSnippetNode = "",
		g_currentTool = "PeripheralConfigure",
		g_groupIds = {},
		g_recordedIds = {},
		g_perControls = {},
		g_enabledThirdPartyLibNodes = [],
		g_enabledPeripheralFunctionNodes = [],
		g_enabledPeripheralFunctionData = {},
		g_field1SubDIVs = [],
		g_field1SubDIVsCache = {},
		g_module_snippet = [],
		g_module_snippet_primitive = [],
		g_module_snippet_buttonId = [],
		g_module_snippet_code = [],
		g_module_snippet_header = [],
		g_module_snippet_pin = [],
		g_module_snippet_clock = [],
		g_module_snippet_peripheral = [],
		g_alpacaFormRepository = [],
		g_object = {},
		g_toast_pin,
		g_toast_clock,
		g_toast_peripheral,
		g_alpacaFormIndex = 0,
		g_field1SubIndex = 0,
		g_thirdPartyLibTreeHeight = 0,
		g_readConfigFile,
		g_userSelectUIlanguage,
		g_bReadyForRelease = true, // should be true For Release
		g_bDevelopingTool = false,  // should be false For Release
		g_bPressEnter = false,
		g_bInvokedByCDHtmlDialog = true,
		g_bAlpacaValidationResult = true,
		g_bCheckNodesBasedOnConfigFile = true;

	// after the browser has downloaded all the data, it will run the window.onload function.
	window.onload = function () {
		if (typeof NUTOOL_PIN !== 'undefined') {
			if (determineIEversion()) { return; } // determine the installed IE version
			decideUIlanguage(); // for toolbar tips
			try { external.updateCurrentDialogSize(); } catch (err) { g_bInvokedByCDHtmlDialog = false; }
			decideNuToolSetup();

			NUTOOL_PIN.loadPinConfigureTool();
			NUTOOL_CLOCK.loadClockConfigureTool();

			if (!decideChipTypeAndTreeContent()) {
				g_bCheckNodesBasedOnConfigFile = false;
			}
			showPeripheralConfigure();
			
			if(g_bWebVersion){
				return;
			}
			
			// construct the selects of chip type and MCU.
			buildChipTypeSelect();
			// construct trees
			$('#rootTree_Peripheral')[0].setAttribute('style', 'width:' + g_NUC_TreeView_Width + 'px; height: ' + g_NUC_TreeView_Height + 'px;');
			buildThirdPartyLibTree();
			buildPerFunctionTree();
			buildControlContainer();
			// determine the caption of the dialog
			try { external.changeDialogCaptionFromJS('NuTool - CodeGenerator_' + NUTOOL_PER.g_toolVersion); } catch (err) { } //+': ' + g_partNumber_package); } catch (err) { }
			//constrainMouseClick();
			// the following is used for testing. When the driver is being released, we should comment them.
			if (!g_bReadyForRelease) {
				decideHotKeys();
			}
		}
		else {
			if (determineIEversion()) { return; } // determine the installed IE version
			decideUIlanguage(); // for toolbar tips
			try { external.updateCurrentDialogSize(); } catch (err) { g_bInvokedByCDHtmlDialog = false; }
			decideNuToolSetup();
			if (!decideChipTypeAndTreeContent()) {
				g_bCheckNodesBasedOnConfigFile = false;
			}
			// construct the selects of chip type and MCU.
			buildChipTypeSelect();
			// construct trees
			$('#rootTree_Peripheral')[0].setAttribute('style', 'width:' + g_NUC_TreeView_Width + 'px; height: ' + g_NUC_TreeView_Height + 'px;');
			buildThirdPartyLibTree();
			buildPerFunctionTree();
			buildControlContainer();
			//constrainMouseClick();
			// the following is used for testing. When the driver is being released, we should comment them.
			if (!g_bReadyForRelease) {
				decideHotKeys();
			}
		}
		NUTOOL_PER.g_bFunctionalTesting = false;
	};

	function buildControlContainer() {
		var ctx,
			img;

		$("#CodeGeneratorContainer")[0].setAttribute('style', 'width:' + (g_Dialog_Width - g_NUC_TreeView_Width + 16) + 'px; height:' + g_Dialog_Height + 'px; border: 1px solid white; position:absolute; left:' + (g_NUC_TreeView_Width - 16) + 'px; top:0px; overflow-y: scroll;'); //background-color:green;
		$("#canvas_Peripheral").hide();
		$('#GenerateCode_pre').hide();

		if ($("#field1_canvas").length === 0) {
			$("#field1").append('<canvas id="field1_canvas" width="' + (g_Dialog_Width - g_NUC_TreeView_Width - 18) + '" height="24"></canvas>');
		}
		ctx = $('#field1_canvas')[0].getContext('2d');
		img = new Image();
		img.src = 'nuvoton.bmp';
		img.onload = function () {
			ctx.drawImage(img, 0, 0);
		};
		if ($("#field1_anchor").length === 0) {
			$("#field1").append('<a id="field1_anchor" href="PeripheralConfigure/quickstart.html" target="_blank" style="color:black;"><span id="field1_span" style="font-size:18px;font-family=arial; position: absolute; top: 35%; left: 10%;"></span></a>');
		}
		decideUIlanguage();
		if (g_userSelectUIlanguage.indexOf("Simplified") !== -1) {
			$("#field1_span").html("欢迎来到NuTool - CodeGenerator。<br />您可以在这里配置外设功能并生成源代码。<br />玩得开心！ (观看快速上手&#128214;)");
		}
		else if (g_userSelectUIlanguage.indexOf("Traditional") !== -1) {
			$("#field1_span").html("歡迎來到NuTool - CodeGenerator。<br />您可以在這裡配置週邊功能並生成原始碼。<br />玩得開心！ (觀看快速上手&#128214;)");
		}
		else {
			$("#field1_span").html("Welcome to NuTool - CodeGenerator.<br />You can configure peripheral functions and generate code here.<br />Have fun! (Watch Quick Start &#128214;)");
		}
	}

	function buildThirdPartyLibTree() {
		var i,
			max,
			j,
			maxJ,
			thirdPartyLibs = [],
			moduleNames = [],
			module_thirdPartyLibs = [],
			attr = {},
			jsonData = {},
			jsonChildData = {},
			jsonDataArray = [],
			jsonChildDataArray = [],
			$rootTree = $('#rootTree_Peripheral'),
			$supportedthirdPartyLibs,
			$supportedthirdPartyLibs_span,
			moduleName,
			content = "";

		thirdPartyLibs = NUTOOL_PER.g_cfg_thirdPartyLibs;
		if (thirdPartyLibs.length === 0) {
			g_thirdPartyLibTreeHeight = 0;
			return;
		}

		module_thirdPartyLibs = [];
		for (i = 0, max = thirdPartyLibs.length; i < max; i += 1) {
			moduleName = content = thirdPartyLibs[i];

			if ($.inArray(moduleName, moduleNames) === -1) {
				moduleNames.push(moduleName);
				module_thirdPartyLibs[moduleName] = [];
			}

			module_thirdPartyLibs[moduleName].push(content);
		}
		moduleNames.sort(natualSort);

		// decide the tree height
		g_thirdPartyLibTreeHeight = (moduleNames.length) * 18;

		// populate the json_data
		jsonDataArray = [];
		for (i = 0, max = moduleNames.length; i < max; i += 1) {
			moduleName = moduleNames[i];

			if (module_thirdPartyLibs[moduleName].length > 1) {
				jsonChildDataArray = [];
				for (j = 0, maxJ = module_thirdPartyLibs[moduleName].length; j < maxJ; j += 1) {
					content = module_thirdPartyLibs[moduleName][j];

					jsonChildData = {};
					attr = {};

					attr.id = content.replaceSpecialCharacters() + '_PeripheralConfigure';
					jsonChildData.data = content;
					jsonChildData.attr = attr;

					jsonChildDataArray.push(jsonChildData);
				}

				jsonData = {};
				attr = {};

				attr.id = moduleName.replaceSpecialCharacters() + '_PeripheralConfigure';
				jsonData.data = moduleName;
				jsonData.attr = attr;
				jsonData.children = jsonChildDataArray;
				jsonData.state = 'closed';
			}
			else {
				jsonData = {};
				attr = {};

				attr.id = moduleName.replaceSpecialCharacters() + '_PeripheralConfigure';
				jsonData.data = moduleName;
				jsonData.attr = attr;
				jsonData.state = 'closed';
			}

			jsonDataArray[i] = jsonData;
		}

		// create a tree of supported thirdPartyLibs
		if ($("#thirdPartyLibTree").length === 0) {
			$rootTree[0].appendChild(ce("div", 'supportedthirdPartyLibs', ""));
			$supportedthirdPartyLibs = $("#supportedthirdPartyLibs");
			$supportedthirdPartyLibs.append('<span id=supportedthirdPartyLibs_span></span>');
			$supportedthirdPartyLibs_span = $("#supportedthirdPartyLibs_span");
			$rootTree[0].appendChild(ce("div", 'thirdPartyLibTree', 'Loading...'));
		}
		$supportedthirdPartyLibs[0].setAttribute('style', 'background-color: #FFFFFF; border-right: 16px solid #F2F2F2; border-left: 8px solid #FFFFFF; float:left; width:' + (g_NUC_TreeView_Width - 16) + 'px; height: 22px;');
		$supportedthirdPartyLibs.css('font-weight', 'bold');
		$thirdPartyLibTree = $("#thirdPartyLibTree");

		$thirdPartyLibTree[0].setAttribute('style', 'background-color: #FFFFFF; overflow-y: scroll; border-left: 8px solid #FFFFFF; float:left; width:' + (g_NUC_TreeView_Width - 16) + 'px; height: ' + g_thirdPartyLibTreeHeight + 'px;');

		decideUIlanguage();
		if (g_userSelectUIlanguage.indexOf("Simplified") !== -1) {
			$thirdPartyLibTree[0].innerHTML = '载入中...';
			$supportedthirdPartyLibs_span.text('第三方函式库');
		}
		else if (g_userSelectUIlanguage.indexOf("Traditional") !== -1) {
			$thirdPartyLibTree[0].innerHTML = '載入中...';
			$supportedthirdPartyLibs_span.text('第三方函式庫');
		}
		else {
			$thirdPartyLibTree[0].innerHTML = 'Loading...';
			$supportedthirdPartyLibs_span.text('Third Party Libraries');
		}

		$thirdPartyLibTree.jstree({
			"themes": {
				"theme": "classic",
				"icons": false
			},
			"json_data": { "data": jsonDataArray },
			'core': {
				'animation': 0
			},
			"plugins": ["themes", "json_data", "checkbox", "ui"]
		}).bind('check_node.jstree', function (e, data) {
			var currentNode = data.rslt.obj.attr("id");

			if ($("#" + currentNode).find("li").length > 0) {
				$thirdPartyLibTree.jstree("uncheck_node", $('#' + currentNode));
				$thirdPartyLibTree.jstree("open_node", $('#' + currentNode));
				return;
			}
		}).bind('uncheck_node.jstree', function (e, data) {
		}).bind('select_node.jstree', function (e, data) {
		}).bind('loaded.jstree', function (e, data) { // invoked after jstree has loaded
			if (g_bCheckNodesBasedOnConfigFile) {
				// based on the saved config file, restore to the saved circumstance
				checkNodesInThirdPartyLibTree();
			}
		}).bind('destroy.jstree', function (e, data) {
		});
	}

	function buildPerFunctionTree() {
		var h,
			i,
			j,
			k,
			max,
			maxJ,
			partNumber = g_partNumber_package.slicePriorToX('('),
			localArray = [],
			perFunctions = [],
			unusedObject = {},
			unusedObjectArray = [],
			unusedObjectProperties = [],
			moduleNames = [],
			attr = {},
			jsonData = {},
			jsonChildData = {},
			jsonDataArray = [],
			jsonChildDataArray = [],
			$rootTree = $('#rootTree_Peripheral'),
			$supportedperFunctions,
			$supportedperFunctions_span,
			$ChipType_span_Peripheral = $("#ChipType_span_Peripheral"),
			$MCU_span_Peripheral = $("#MCU_span_Peripheral"),
			unusedPerFunction,
			pinName,
			content = "",
			precedingPath = "";

		if (g_bInvokedByCDHtmlDialog === false &&
			typeof NUTOOL_PER.g_cfg_perFunctions !== 'undefined' &&
			NUTOOL_PER.g_cfg_perFunctions.length !== 0) {
			localArray = NUTOOL_PER.g_cfg_perFunctions;
		}
		else {
			try { external.findPerFunctionFileFromJS(); } catch (err) { }
			localArray = NUTOOL_PER.g_perFunctionString.split(',').sort(natualSort);
		}

		$.each(localArray, function (i, el) {
			if ($.inArray(el, perFunctions) === -1) perFunctions.push(el);
		});

		if (perFunctions.length === 0) {
			return;
		}

		g_module_snippet_primitive = [];
		for (i = 0, max = perFunctions.length; i < max; i += 1) {
			content = perFunctions[i];
			moduleName = content.slicePriorToX('_').slicePriorToX('.').toString();

			if ($.inArray(moduleName, moduleNames) === -1) {
				moduleNames.push(moduleName);
				g_module_snippet_primitive[moduleName] = [];
			}

			g_module_snippet_primitive[moduleName].push(content.slicePriorToX('.'));
		}

		// find chip type
		g_partNumber_type = decideNewPartNumberType(g_partNumber_package);

		// determine supported GPIO pins
		if (typeof NUTOOL_PIN !== 'undefined') {
			g_supportedGPIOPins = {};
			for (j = 0, maxJ = NUTOOL_PIN.g_cfg_gpios.length; j < maxJ; j += 1) {
				pinName = NUTOOL_PIN.g_cfg_gpios[j].f[0].slicePriorToX(':0');
				if ($.inArray(pinName, NUTOOL_PIN.g_cfg_pkgs[NUTOOL_PIN.g_packageNumberIndex]) !== -1) {
					g_supportedGPIOPins[pinName.replaceSpecialCharacters()] = "1";
				}
				else {
					g_supportedGPIOPins[pinName.replaceSpecialCharacters()] = "0";
				}
			}
		}
		// trim some unused perFunctions if exists
		if (typeof (NUTOOL_PER.g_cfg_unusedPerFunctions) !== 'undefined' && typeof (NUTOOL_PER.g_cfg_unusedPerFunctions[partNumber]) !== 'undefined') {
			if (typeof (NUTOOL_PER.g_cfg_unusedPerFunctions[partNumber]) == "function") {
				unusedObjectArray.push(NUTOOL_PER.g_cfg_unusedPerFunctions[partNumber]());
			}
			else {
				unusedObjectArray.push(NUTOOL_PER.g_cfg_unusedPerFunctions[partNumber]);
			}
		}
		if (g_partNumber_type !== "" &&
			typeof (NUTOOL_PER.g_cfg_unusedPerFunctions) !== 'undefined' &&
			typeof (NUTOOL_PER.g_cfg_unusedPerFunctions[g_partNumber_type]) !== 'undefined') {
			if (typeof (NUTOOL_PER.g_cfg_unusedPerFunctions[g_partNumber_type]) == "function") {
				unusedObjectArray.push(NUTOOL_PER.g_cfg_unusedPerFunctions[g_partNumber_type]());
			}
			else {
				unusedObjectArray.push(NUTOOL_PER.g_cfg_unusedPerFunctions[g_partNumber_type]);
			}
		}

		for (h = 0; h < unusedObjectArray.length; h += 1) {
			unusedObject = unusedObjectArray[h];
			unusedObjectProperties = getPropertyNames(unusedObject);
			for (i = 0; i < unusedObjectProperties.length; i += 1) {
				if (unusedObjectProperties[i] === 'SUBSTRING') {
					// trim the unused GPIO function for the specific module
					for (j = 0, maxJ = unusedObject[unusedObjectProperties[i]].length; j < maxJ; j = j + 1) {
						unusedPerFunction = unusedObject[unusedObjectProperties[i]][j];
						for (k = perFunctions.length - 1; k >= 0; k -= 1) {
							if (perFunctions[k].indexOf(unusedPerFunction) === 0) {
								perFunctions.splice(k, 1);
							}
						}
					}
				}
				else if (unusedObjectProperties[i] === 'FULL') {
					// trim the unused GPIO function for the specific module
					for (j = 0, maxJ = unusedObject[unusedObjectProperties[i]].length; j < maxJ; j = j + 1) {
						unusedPerFunction = unusedObject[unusedObjectProperties[i]][j];
						if (unusedPerFunction.indexOf('.txt') === -1) {
							unusedPerFunction = unusedPerFunction + '.txt';
						}
						for (k = perFunctions.length - 1; k >= 0; k -= 1) {
							if (perFunctions[k] === unusedPerFunction) {
								perFunctions.splice(k, 1);
							}
						}
					}
				}
				else {
					if (!g_bReadyForRelease) { alert('A problem occurred when trimming unused perFunctions.'); }
				}
			}
		}

		moduleNames = [];
		g_module_snippet = [];
		for (i = 0, max = perFunctions.length; i < max; i += 1) {
			content = perFunctions[i];
			moduleName = content.slicePriorToX('_').slicePriorToX('.').toString();

			if ($.inArray(moduleName, moduleNames) === -1) {
				moduleNames.push(moduleName);
				g_module_snippet[moduleName] = [];
			}

			g_module_snippet[moduleName].push(content.slicePriorToX('.'));
		}
		moduleNames.sort(natualSort);

		// populate the json_data
		jsonDataArray = [];
		for (i = 0, max = moduleNames.length; i < max; i += 1) {
			moduleName = moduleNames[i];

			if (g_module_snippet[moduleName].length > 1 ||
				g_module_snippet[moduleName][0].indexOf('_') !== -1) {
				jsonChildDataArray = [];
				for (j = 0, maxJ = g_module_snippet[moduleName].length; j < maxJ; j += 1) {
					content = g_module_snippet[moduleName][j];

					jsonChildData = {};
					attr = {};

					attr.id = content + '_PeripheralConfigure';
					jsonChildData.data = content;
					jsonChildData.attr = attr;

					jsonChildDataArray.push(jsonChildData);
				}

				jsonData = {};
				attr = {};

				attr.id = moduleName + '_PeripheralConfigure';
				jsonData.data = moduleName;
				jsonData.attr = attr;
				jsonData.children = jsonChildDataArray;
				jsonData.state = 'closed';
			}
			else {
				jsonData = {};
				attr = {};

				attr.id = moduleName + '_PeripheralConfigure';
				jsonData.data = moduleName;
				jsonData.attr = attr;
				//jsonData.children = jsonChildDataArray;
				jsonData.state = 'closed';
			}


			jsonDataArray[i] = jsonData;
		}

		// create a tree of supported perFunctions
		if ($("#perFunctionTree").length === 0) {
			$rootTree[0].appendChild(ce("div", 'supportedperFunctions', ""));
			$supportedperFunctions = $("#supportedperFunctions");
			$supportedperFunctions.append('<span id=supportedperFunctions_span></span>');
			$supportedperFunctions_span = $("#supportedperFunctions_span");
			$rootTree[0].appendChild(ce("div", 'perFunctionTree', 'Loading...'));
		}
		$supportedperFunctions[0].setAttribute('style', 'background-color: #FFFFFF; border-right: 16px solid #F2F2F2; border-left: 8px solid #FFFFFF; float:left; width:' + (g_NUC_TreeView_Width - 16) + 'px; height: 22px;');
		$supportedperFunctions.css('font-weight', 'bold');
		$perFunctionTree = $("#perFunctionTree");

		decideUIlanguage();
		if (g_userSelectUIlanguage.indexOf("Simplified") !== -1) {
			$ChipType_span_Peripheral.text('晶片系列:');
			$MCU_span_Peripheral.text('型号:');
			$perFunctionTree[0].innerHTML = '载入中...';
			$supportedperFunctions_span.text('外设功能');
		}
		else if (g_userSelectUIlanguage.indexOf("Traditional") !== -1) {
			$ChipType_span_Peripheral.text('晶片系列:');
			$MCU_span_Peripheral.text('型號:');
			$perFunctionTree[0].innerHTML = '載入中...';
			$supportedperFunctions_span.text('週邊功能');
		}
		else {
			$ChipType_span_Peripheral.text('Chip Series:');
			$MCU_span_Peripheral.text('Part No.:');
			$perFunctionTree[0].innerHTML = 'Loading...';
			$supportedperFunctions_span.text('Peripheral Functions');
		}
		$ChipType_span_Peripheral.css('font-size', '14px');
		$ChipType_span_Peripheral.css('font-weight', 'bold');
		$MCU_span_Peripheral.css('font-size', '14px');
		$MCU_span_Peripheral.css('font-weight', 'bold');

		if (typeof NUTOOL_PIN !== 'undefined') {
			precedingPath = 'PeripheralConfigure//';
		}

		if (g_thirdPartyLibTreeHeight !== 0) {
			$perFunctionTree[0].setAttribute('style', 'background-color: #FFFFFF; overflow-y: scroll; border-left: 8px solid #FFFFFF; float:left; width:' + (g_NUC_TreeView_Width - 16) + 'px; height: ' + (g_NUC_TreeView_Height - $("#ChipType_Peripheral").height() - $("#MCU_Peripheral").height() - $("#supportedperFunctions").height() - g_thirdPartyLibTreeHeight - 20) + 'px;');
		}
		else {
			$perFunctionTree[0].setAttribute('style', 'background-color: #FFFFFF; overflow-y: scroll; border-left: 8px solid #FFFFFF; float:left; width:' + (g_NUC_TreeView_Width - 16) + 'px; height: ' + (g_NUC_TreeView_Height - $("#ChipType_Peripheral").height() - $("#MCU_Peripheral").height() - $("#supportedperFunctions").height()) + 'px;');
		}
		$perFunctionTree.jstree({
			"themes": {
				"theme": "default",
				"icons": false,
				"jstree_ins": false,
			},
			"json_data": { "data": jsonDataArray },
			'core': {
				'animation': 0
			},
			"plugins": ["themes", "json_data", "checkbox", "ui"]
		}).bind('check_node.jstree', function (e, data) {
			var i,
				max,
				currentNode = data.rslt.obj.attr("id"),
				semiDisabledNode;

			// return unless alpaca finished building
			if (!checkAlpacaReady()) {
				if (!g_bReadyForRelease && window.console) { window.console.log("In check_node, return unless alpaca finished building: " + currentNode); }
				$('#' + currentNode).removeClass('jstree-checked jstree-undetermined').addClass('jstree-unchecked');
				return;
			}
			// prevent the user from generating wrong code
			if (!g_bAlpacaValidationResult) {
				$('#' + currentNode).removeClass('jstree-checked jstree-undetermined').addClass('jstree-unchecked');
				showWarningForFieldsInvalid(
					g_lastCheckedSnippetNode.slicePriorToX('_PeripheralConfigure'),
					function () {
						restorePerControlsToDefault(precedingPath + g_chipType + '//' + g_lastCheckedSnippetNode.slicePriorToX('_PeripheralConfigure') + '.txt');
						delete g_field1SubDIVsCache[g_lastCheckedSnippetNode.slicePriorToX('_PeripheralConfigure')];
						alpacaValidationSuccess();
						$('#perFunctionTree').jstree("uncheck_node", $('#' + g_lastCheckedSnippetNode));
					});
				return;
			}

			$.toast().reset('all');

			if ($("#" + currentNode).find("li").length > 0) {
				$perFunctionTree.jstree("uncheck_node", $('#' + currentNode));
				if ($('#' + currentNode).hasClass('jstree-closed')) {
					$perFunctionTree.jstree("open_node", $('#' + currentNode));
				}
				else {
					$perFunctionTree.jstree("close_node", $('#' + currentNode));
				}
				return;
			}
			if (currentNode !== g_lastCheckedSnippetNode &&
				$("#" + g_lastCheckedSnippetNode).hasClass('jstree-checked') &&
				$("#" + g_module_snippet_buttonId[g_lastCheckedSnippetNode.slicePriorToX('_PeripheralConfigure')]).alpaca("exists")) {
				$("#" + g_module_snippet_buttonId[g_lastCheckedSnippetNode.slicePriorToX('_PeripheralConfigure')]).alpaca("get").form.getButtonEl("submit").click();
			}
			g_lastCheckedSnippetNode = currentNode;
			// handle the semi-disabled nodes
			if ($("#" + currentNode).hasClass('semi-disabled')) {
				moduleName = currentNode.slicePriorToX('_');
				for (j = 0, maxJ = g_module_snippet[moduleName].length; j < maxJ; j += 1) {
					semiDisabledNode = g_module_snippet[moduleName][j] + '_PeripheralConfigure';
					if (currentNode !== semiDisabledNode &&
						$("#" + semiDisabledNode).hasClass('jstree-checked')) {
						$perFunctionTree.jstree("uncheck_node", $('#' + semiDisabledNode));
					}
				}
			}

			$("#field1_canvas").remove();
			$("#field1_anchor").remove();

			for (i = 0, max = g_field1SubDIVs.length; i < max; i += 1) {
				if (typeof ($("#" + g_field1SubDIVs[i])) !== 'undefined') {
					$("#" + g_field1SubDIVs[i]).hide();
				}
			}
			if (typeof g_field1SubDIVsCache[currentNode.slicePriorToX('_PeripheralConfigure')] === 'undefined') {
				if (!g_bReadyForRelease && window.console) { window.console.log("In check_node, build a new txt: " + currentNode); }
				currentNode = currentNode.slicePriorToX('_PeripheralConfigure');
				g_currentSnippetFilePath = precedingPath + g_chipType + '//' + currentNode + '.txt';
				g_currentSnippetLayoutath = './' + precedingPath + g_chipType + '/' + currentNode + '.html';
				preprocessTagFile(currentNode);
				decidePerControls(precedingPath + g_chipType + '//' + currentNode + '.txt', currentNode);
				buildAlpaca(currentNode);
			}
			else {
				currentNode = currentNode.slicePriorToX('_PeripheralConfigure');
				for (i = 0, max = g_field1SubDIVsCache[currentNode].length; i < max; i += 1) {
					if (typeof ($("#" + g_field1SubDIVsCache[currentNode][i])) !== 'undefined') {
						if (!g_bReadyForRelease && window.console) { window.console.log("In check_node, show the previous div: " + g_field1SubDIVsCache[currentNode][i]); }
						$("#" + g_field1SubDIVsCache[currentNode][i]).show();
					}
				}
				// restore UI
				$("#canvas_Peripheral").hide();
				$("#GenerateCode_pre").empty();
				$("#GenerateCode_pre").hide();
				$('.prettyprinted').removeClass('prettyprinted');
				// update canvas_Peripheral
				if ($("#" + g_module_snippet_buttonId[currentNode]).alpaca("exists")) {
					$("#" + g_module_snippet_buttonId[currentNode]).alpaca("get").form.getButtonEl("submit").click();
				}
			}
		}).bind('uncheck_node.jstree', function (e, data) {
			var i,
				max,
				currentNode = data.rslt.obj.attr("id").slicePriorToX('_PeripheralConfigure'),
				$field1 = $("#field1"),
				ctx,
				img,
				uncheck_node_core;

			uncheck_node_core = function () {
				$.toast().reset('all');

				for (i = 0, max = g_field1SubDIVs.length; i < max; i += 1) {
					if (typeof ($("#" + g_field1SubDIVs[i])) !== 'undefined') {
						$("#" + g_field1SubDIVs[i]).hide();
					}
				}
				$("#canvas_Peripheral").hide();
				$("#GenerateCode_pre").empty();
				$("#GenerateCode_pre").hide();
				$('.prettyprinted').removeClass('prettyprinted');

				if ($("#field1_canvas").length === 0) {
					$("#field1").append('<canvas id="field1_canvas" width="' + (g_Dialog_Width - g_NUC_TreeView_Width - 18) + '" height="24"></canvas>');
				}
				ctx = $('#field1_canvas')[0].getContext('2d');
				img = new Image();
				img.src = 'nuvoton.bmp';
				img.onload = function () {
					ctx.drawImage(img, 0, 0);
				};
				if ($("#field1_span").length === 0) {
					$field1.append('<a id="field1_anchor" href="PeripheralConfigure/quickstart.html" target="_blank" style="color:black;"><span id="field1_span" style="font-size:18px;font-family=arial; position: absolute; top: 35%; left: 10%;"></span></a>');
				}
				decideUIlanguage();
				if (g_userSelectUIlanguage.indexOf("Simplified") !== -1) {
					$("#field1_span").html("欢迎来到NuTool - CodeGenerator。<br />您可以在这里配置外设功能并生成源代码。<br />玩得开心！ (观看快速上手&#128214;)");
				}
				else if (g_userSelectUIlanguage.indexOf("Traditional") !== -1) {
					$("#field1_span").html("歡迎來到NuTool - CodeGenerator。<br />您可以在這裡配置週邊功能並生成原始碼。<br />玩得開心！ (觀看快速上手&#128214;)");
				}
				else {
					$("#field1_span").html("Welcome to NuTool - CodeGenerator.<br />You can configure peripheral functions and generate code here.<br />Have fun! (Watch Quick Start &#128214;)");
				}

				delete g_module_snippet_code[currentNode];
				delete g_module_snippet_header[currentNode];
				delete g_module_snippet_pin[currentNode];
				delete g_module_snippet_clock[currentNode];
				delete g_module_snippet_peripheral[currentNode];
			};

			// prevent the user from generating wrong code
			if (g_bAlpacaValidationResult) {
				uncheck_node_core();
			}
			else {
				$('#' + currentNode + '_PeripheralConfigure').removeClass('jstree-unchecked jstree-undetermined').addClass('jstree-checked');
				showWarningForFieldsInvalid(
					currentNode,
					function () {
						$('#' + currentNode + '_PeripheralConfigure').removeClass('jstree-checked jstree-undetermined').addClass('jstree-unchecked');
						restorePerControlsToDefault(precedingPath + g_chipType + '//' + currentNode + '.txt');
						delete g_field1SubDIVsCache[currentNode];
						alpacaValidationSuccess();
						uncheck_node_core();
					});
			}
		}).bind('select_node.jstree', function (e, data) {
			var i,
				max,
				currentNode = data.rslt.obj.attr("id");
			// prevent the user from generating wrong code
			if (!g_bAlpacaValidationResult) {
				showWarningForFieldsInvalid(
					g_lastCheckedSnippetNode.slicePriorToX('_PeripheralConfigure'),
					function () {
						restorePerControlsToDefault(precedingPath + g_chipType + '//' + g_lastCheckedSnippetNode.slicePriorToX('_PeripheralConfigure') + '.txt');
						delete g_field1SubDIVsCache[g_lastCheckedSnippetNode.slicePriorToX('_PeripheralConfigure')];
						alpacaValidationSuccess();
						$('#perFunctionTree').jstree("uncheck_node", $('#' + g_lastCheckedSnippetNode));
					});
				return;
			}

			$.toast().reset('all');

			// return unless alpaca finished building
			if (!checkAlpacaReady()) {
				if (!g_bReadyForRelease && window.console) { window.console.log("In select_node, return unless alpaca finished building: " + currentNode); }
				return;
			}

			if ($("#" + currentNode).find("li").length === 0 && $("#" + currentNode).hasClass('jstree-checked')) {
				$("#field1_canvas").remove();
				$("#field1_anchor").remove();

				if (currentNode !== g_lastCheckedSnippetNode &&
					$("#" + g_lastCheckedSnippetNode).hasClass('jstree-checked') &&
					$("#" + g_module_snippet_buttonId[g_lastCheckedSnippetNode.slicePriorToX('_PeripheralConfigure')]).alpaca("exists")) {
					$("#" + g_module_snippet_buttonId[g_lastCheckedSnippetNode.slicePriorToX('_PeripheralConfigure')]).alpaca("get").form.getButtonEl("submit").click();
				}
				g_lastCheckedSnippetNode = currentNode;
				for (i = 0, max = g_field1SubDIVs.length; i < max; i += 1) {
					if (typeof ($("#" + g_field1SubDIVs[i])) !== 'undefined') {
						$("#" + g_field1SubDIVs[i]).hide();
					}
				}
				if (typeof g_field1SubDIVsCache[currentNode.slicePriorToX('_PeripheralConfigure')] === 'undefined') {
					if (!g_bReadyForRelease && window.console) { window.console.log("In select_node, build a new txt: " + currentNode); }
					currentNode = currentNode.slicePriorToX('_PeripheralConfigure');
					g_currentSnippetFilePath = precedingPath + g_chipType + '//' + currentNode + '.txt';
					g_currentSnippetLayoutath = './' + precedingPath + g_chipType + '/' + currentNode + '.html';
					preprocessTagFile(currentNode);
					decidePerControls(precedingPath + g_chipType + '//' + currentNode + '.txt', currentNode);
					buildAlpaca(currentNode);
				}
				else {
					currentNode = currentNode.slicePriorToX('_PeripheralConfigure');
					for (i = 0, max = g_field1SubDIVsCache[currentNode].length; i < max; i += 1) {
						if (typeof ($("#" + g_field1SubDIVsCache[currentNode][i])) !== 'undefined') {
							if (!g_bReadyForRelease && window.console) { window.console.log("In select_node, show the previous div: " + g_field1SubDIVsCache[currentNode][i]); }
							$("#" + g_field1SubDIVsCache[currentNode][i]).show();
						}
					}
					// restore UI
					$("#canvas_Peripheral").hide();
					$("#GenerateCode_pre").empty();
					$("#GenerateCode_pre").hide();
					$('.prettyprinted').removeClass('prettyprinted');
					// update canvas_Peripheral
					if ($("#" + g_module_snippet_buttonId[currentNode]).alpaca("exists")) {
						$("#" + g_module_snippet_buttonId[currentNode]).alpaca("get").form.getButtonEl("submit").click();
					}
				}
			}
		}).bind('loaded.jstree', function (e, data) { // invoked after jstree has loaded
			// handle the semi-disabled nodes
			if (typeof NUTOOL_PER.g_cfg_perFuncMutex !== 'undefined') {
				for (i = 0, max = NUTOOL_PER.g_cfg_perFuncMutex.length; i < max; i += 1) {
					moduleName = NUTOOL_PER.g_cfg_perFuncMutex[i];
					$("#" + moduleName + '_PeripheralConfigure').addClass('semi-disabled');
					if (typeof g_module_snippet[moduleName] !== 'undefined') {
						for (j = 0, maxJ = g_module_snippet[moduleName].length; j < maxJ; j += 1) {
							$("#" + g_module_snippet[moduleName][j] + '_PeripheralConfigure').addClass('semi-disabled');
						}
						$("#" + moduleName + "_PeripheralConfigure >a").css("background-color", "#B0C4DE");
					}
				}
			}

			if (g_bCheckNodesBasedOnConfigFile &&
				g_bInvokedByCDHtmlDialog) {
				// based on the saved config file, restore to the saved circumstance
				checkNodesInPerFunctionTree();
				// clear this to release ram.
				g_readConfigFile = null;
			}
			else {
				g_bCheckNodesBasedOnConfigFile = true;
			}
		}).bind('destroy.jstree', function (e, data) {
		});
	}

	function buildAlpaca(snippetName) {
		var i,
			j,
			max,
			maxJ,
			precedingPath = "",
			readSnippetFilePath,
			newUpdatedSnippetFile = "",
			newUpdatedSnippetCode = "",
			subDivBase = 40,
			subDivCount,
			alpacaForm = {},
			local_perControls = g_perControls[snippetName],
			localControl,
			localObject,
			localFieldId,
			localGroupId,
			localPin = null,
			localClock = null,
			localPeripheral = null,
			decideSubDivBase,
			generateCodeFunction,
			alpacaControlEvents,
			postRender;

		decideSubDivBase = function (searchKey) {
			var i,
				j,
				max,
				maxJ,
				tagKeyRecords = [],
				tagIndexArray = {},
				subDivTest,
				subDivIndex,
				localKeys,
				localMaxIndex,
				maxIndex;

			for (i = 0, max = local_perControls.length; i < max; i += 1) {
				if (typeof local_perControls[i][searchKey] !== 'undefined' &&
					local_perControls[i][searchKey] !== "none" &&
					local_perControls[i][searchKey] !== "") {
					localControl = local_perControls[i];
					if (typeof tagIndexArray[localControl[searchKey]] === "undefined") {
						tagIndexArray[localControl[searchKey]] = [];
					}
					tagIndexArray[localControl[searchKey]].push(i + 1);

					if (tagKeyRecords.indexOf(localControl[searchKey]) === -1) {
						tagKeyRecords.push(localControl[searchKey]);
					}
				}
			}
			if (tagKeyRecords.length === 0) {
				return;
			}

			for (i = 0, max = tagKeyRecords.length; i < max; i += 1) {
				localKeys = tagKeyRecords[i];
				for (j = 0, maxJ = local_perControls.length; j < maxJ; j += 1) {
					if (!Array.isArray(localKeys) &&
						localKeys.toString().trim() === local_perControls[j].id) {
						tagIndexArray[localKeys].push(j + 1);
					}
					else if (localKeys.indexOf(local_perControls[j].id) !== -1) {
						tagIndexArray[localKeys].push(j + 1);
					}
				}
			}
			do {
				subDivTest = false;
				for (i = 1, max = 500; i < max; i += 1) { // assume the maximum number of controls is 20000 (40 * 500)
					subDivIndex = subDivBase * i;
					maxIndex = 0;
					for (j = 0, maxJ = tagKeyRecords.length; j < maxJ; j += 1) {
						localKeys = tagKeyRecords[j];
						localMaxIndex = Math.max.apply(null, tagIndexArray[localKeys]);
						if (subDivIndex >= Math.min.apply(null, tagIndexArray[localKeys]) &&
							subDivIndex < localMaxIndex) {
							subDivTest = false;
							i = max;
							break;
						}
						if (maxIndex < localMaxIndex) {
							maxIndex = localMaxIndex;
						}
						if (j === maxJ - 1 &&
							subDivIndex >= maxIndex) {
							subDivTest = true;
							i = max;
							break;
						}
					}
				} // for (i = 1, max = 500; i < max; i += 1) {

				if (subDivTest) {
					break;
				}
				subDivBase = subDivBase + 1;
			} while (subDivBase < 20000);
			if (!g_bReadyForRelease && !subDivTest) { alert('A problem occurred in decideSubDivBase.'); }
		};

		generateCodeFunction = function () {
			var i,
				j,
				k,
				max,
				maxJ,
				maxK,
				val = this.getValue(),
				currentButtonId,
				currentButtonTitle,
				currentField1SubDIVIndex,
				nextIndex,
				nextButtonId,
				tagIds = getPropertyNames(val),
				tagIds1,
				localId,
				localId1,
				localValue,
				localHeader = "",
				localObject = null,
				tempString,
				f1;

			f1 = function () {
				localHeader = "";
				// handle the multipleselect and checkbox control which selects nothing
				for (i = 0, max = local_perControls.length; i < max; i += 1) {
					if (typeof local_perControls[i].id !== 'undefined' &&
						local_perControls[i].id !== 'undefined' &&
						$.inArray(local_perControls[i].id, g_recordedIds[snippetName]) === -1 &&
						(local_perControls[i].type === 'multipleselect' || local_perControls[i].type === 'checkbox')) {
						localId = local_perControls[i].id;
						localValue = '0';
						newUpdatedSnippetFile = replaceTag(newUpdatedSnippetFile, localId, localValue, 'data:');
						newUpdatedSnippetCode = replaceTag(newUpdatedSnippetCode, localId, localValue, 'entireTag');
					}
					if (typeof local_perControls[i].id !== 'undefined' &&
						local_perControls[i].id !== 'undefined' &&
						$.inArray(local_perControls[i].id, g_recordedIds[snippetName]) === -1) {
						localId = local_perControls[i].id;
						if (typeof local_perControls[i].default !== 'undefined') {
							localValue = local_perControls[i].default.toString().replace(/\[/g, "").replace(/\]/g, "").replace(/,/g, "|").trim();
						}
						else {
							localValue = 'NUC_NULL';
						}
						if (typeof local_perControls[i].dependenciesDefault !== 'undefined' &&
							local_perControls[i].dependenciesDefault !== 'true') {
							localValue = 'NUC_NULL';
						}
						newUpdatedSnippetCode = replaceTag(newUpdatedSnippetCode, localId, localValue, 'entireTag');
					}
					if (typeof local_perControls[i].header !== 'undefined') {
						localHeader = local_perControls[i].header.replace(/\//g, "\\");
					}
				}
				// handle the requirement for pin and clock
				if (localPin !== null && typeof localPin.ALL !== 'undefined') {
					if (typeof g_module_snippet_pin[snippetName] === 'undefined') {
						g_module_snippet_pin[snippetName] = [];
					}
					if (!Array.isArray(localPin.ALL)) {
						if ($.inArray(localPin.ALL, g_module_snippet_pin[snippetName]) === -1) {
							g_module_snippet_pin[snippetName].push(localPin.ALL);
						}
					}
					else {
						for (j = 0, maxJ = localPin.ALL.length; j < maxJ; j += 1) {
							if ($.inArray(localPin.ALL[j], g_module_snippet_pin[snippetName]) === -1) {
								g_module_snippet_pin[snippetName].push(localPin.ALL[j]);
							}
						}
					}
				}
				if (localClock !== null && typeof localClock.ALL !== 'undefined') {
					if (typeof g_module_snippet_clock[snippetName] === 'undefined') {
						g_module_snippet_clock[snippetName] = [];
					}
					if (!Array.isArray(localClock.ALL)) {
						if ($.inArray(localClock.ALL, g_module_snippet_clock[snippetName]) === -1) {
							g_module_snippet_clock[snippetName].push(localClock.ALL);
						}
					}
					else {
						for (j = 0, maxJ = localClock.ALL.length; j < maxJ; j += 1) {
							if ($.inArray(localClock.ALL[j], g_module_snippet_clock[snippetName]) === -1) {
								g_module_snippet_clock[snippetName].push(localClock.ALL[j]);
							}
						}
					}
				}
				if (localPeripheral !== null && typeof localPeripheral.ALL !== 'undefined') {
					if (typeof g_module_snippet_peripheral[snippetName] === 'undefined') {
						g_module_snippet_peripheral[snippetName] = [];
					}
					if (!Array.isArray(localPeripheral.ALL)) {
						if ($.inArray(localPeripheral.ALL, g_module_snippet_peripheral[snippetName]) === -1) {
							g_module_snippet_peripheral[snippetName].push(localPeripheral.ALL);
						}
					}
					else {
						for (j = 0, maxJ = localPeripheral.ALL.length; j < maxJ; j += 1) {
							if ($.inArray(localPeripheral.ALL[j], g_module_snippet_peripheral[snippetName]) === -1) {
								g_module_snippet_peripheral[snippetName].push(localPeripheral.ALL[j]);
							}
						}
					}
				}
				// initialization
				g_recordedIds[snippetName] = [];

				if (newUpdatedSnippetFile !== g_updatedSnippetFile) {
					g_updatedSnippetFile = newUpdatedSnippetFile;
					try { external.updateSnippetFileFromJs(); } catch (err) { }
				}

				if (NUTOOL_PER.drawCanvas("canvas_Peripheral", g_chipType, g_object, snippetName)) {
					$("#canvas_Peripheral").show();
				}
				else {
					$("#canvas_Peripheral").hide();
				}
				$("#GenerateCode_pre").empty();
				$('.prettyprinted').removeClass('prettyprinted');
				if ($("#GenerateCode_span").length === 0) {
					$("#GenerateCode_pre").append('<span id="GenerateCode_span"></span>');
				}
				newUpdatedSnippetCode = removeAllTags(newUpdatedSnippetCode);
				if (!g_bReadyForRelease && window.console) { window.console.log("In generateCodeFunction: " + newUpdatedSnippetCode); }
				if (g_bDevelopingTool && !NUTOOL_PER.g_bFunctionalTesting) {
					$("#GenerateCode_span").text(newUpdatedSnippetCode);
					prettyPrint();
					$('#GenerateCode_pre').show();
				}
				g_module_snippet_code[snippetName] = newUpdatedSnippetCode;
				if (localHeader !== "") {
					if (localHeader.indexOf(".h") !== -1) {
						g_module_snippet_header[snippetName] = localHeader;
					}
					else {
						g_module_snippet_header[snippetName] = localHeader + ".h";
					}
				}
				else {
					g_module_snippet_header[snippetName] = "periph_conf.h";
				}

				newUpdatedSnippetFile = "";
				newUpdatedSnippetCode = "";
			};
			// function entry
			currentButtonId = this.options.buttons.submit.id;
			currentButtonTitle = this.options.buttons.submit.title;
			currentField1SubDIVIndex = parseInt(currentButtonId.sliceAfterX('field1_sub'), 10);
			nextIndex = currentField1SubDIVIndex - 1;

			if (currentButtonTitle.indexOf("Continue") === -1) {
				g_currentSnippetFilePath = readSnippetFilePath;
				newUpdatedSnippetCode = newUpdatedSnippetFile = g_updatedSnippetFile = $.ajax({ url: readSnippetFilePath, async: false }).responseText.replace(/\r/g, "");

				g_object = {};
				g_object.clock = {};
				g_object.peripheral = {};

				tempString = ":";
				for (i = 0, max = local_perControls.length; i < max; i += 1) {
					if (typeof local_perControls[i].id !== 'undefined') {
						tempString += local_perControls[i].id;
						if (i !== max - 1) {
							tempString += '/:';
						}
						else {
							tempString += '/';
						}
					}
				}
				g_object.peripheralAllIds = tempString;
				if (typeof NUTOOL_CLOCK !== 'undefined') {
					NUTOOL_CLOCK.getGeneratedClockStatus();
					g_object.clock = JSON.parse(NUTOOL_CLOCK.getg_clockRegsString1());
				}
				// handle the requirement for pin and clock
				localPin = null;
				localClock = null;
				localPeripheral = null;
				for (i = 0, max = local_perControls.length; i < max; i += 1) {
					if (typeof local_perControls[i].pin !== 'undefined') {
						if (typeof local_perControls[i].pin[g_partNumber_type] !== 'undefined') {
							localPin = local_perControls[i].pin[g_partNumber_type];
						}
						if (typeof local_perControls[i].pin[g_partNumber_package.slicePriorToX('(')] !== 'undefined') {
							localPin = local_perControls[i].pin[g_partNumber_package.slicePriorToX('(')];
						}
						if (localPin === null) {
							localPin = local_perControls[i].pin;
						}
					}
					if (typeof local_perControls[i].clock !== 'undefined') {
						if (typeof local_perControls[i].clock[g_partNumber_type] !== 'undefined') {
							localClock = local_perControls[i].clock[g_partNumber_type];
						}
						if (typeof local_perControls[i].clock[g_partNumber_package.slicePriorToX('(')] !== 'undefined') {
							localClock = local_perControls[i].clock[g_partNumber_package.slicePriorToX('(')];
						}
						if (localClock === null) {
							localClock = local_perControls[i].clock;
						}
					}
					if (typeof local_perControls[i].peripheral !== 'undefined') {
						if (typeof local_perControls[i].peripheral[g_partNumber_type] !== 'undefined') {
							localPeripheral = local_perControls[i].peripheral[g_partNumber_type];
						}
						if (typeof local_perControls[i].peripheral[g_partNumber_package.slicePriorToX('(')] !== 'undefined') {
							localPeripheral = local_perControls[i].peripheral[g_partNumber_package.slicePriorToX('(')];
						}
						if (localPeripheral === null) {
							localPeripheral = local_perControls[i].peripheral;
						}
					}
					if (localPin !== null && localClock !== null && localPeripheral !== null) {
						break;
					}
				}
				delete g_module_snippet_pin[snippetName];
				delete g_module_snippet_clock[snippetName];
				delete g_module_snippet_peripheral[snippetName];
			}

			if (nextIndex >= 0) {
				nextButtonId = "field1_sub" + nextIndex;
				if (typeof ($("#" + nextButtonId)) !== 'undefined' &&
					$("#" + nextButtonId).length !== 0 &&
					$("#" + nextButtonId).alpaca("exists") &&
					$("#" + nextButtonId).is(':visible')) {
					$("#" + nextButtonId).alpaca("get").form.getButtonEl("submit").click();
				}
			}

			if (tagIds.length > 0) {
				for (i = 0, max = tagIds.length; i < max; i += 1) {
					localId = tagIds[i];
					if ($.inArray(localId, g_groupIds[snippetName]) === -1) {
						g_recordedIds[snippetName].push(localId);

						if (localPin !== null &&
							typeof localPin[localId] !== 'undefined' &&
							typeof localPin[localId][val[localId]] !== 'undefined') {
							if (typeof g_module_snippet_pin[snippetName] === 'undefined') {
								g_module_snippet_pin[snippetName] = [];
							}
							localObject = localPin[localId][val[localId]];
							if (!Array.isArray(localObject)) {
								if ($.inArray(localObject, g_module_snippet_pin[snippetName]) === -1) {
									g_module_snippet_pin[snippetName].push(localObject);
								}
							}
							else {
								for (j = 0, maxJ = localObject.length; j < maxJ; j += 1) {
									if ($.inArray(localObject[j], g_module_snippet_pin[snippetName]) === -1) {
										g_module_snippet_pin[snippetName].push(localObject[j]);
									}
								}
							}
						}
						if (localClock !== null &&
							typeof localClock[localId] !== 'undefined' &&
							typeof localClock[localId][val[localId]] !== 'undefined') {
							if (typeof g_module_snippet_clock[snippetName] === 'undefined') {
								g_module_snippet_clock[snippetName] = [];
							}
							localObject = localClock[localId][val[localId]];
							if (!Array.isArray(localObject)) {
								if ($.inArray(localObject, g_module_snippet_clock[snippetName]) === -1) {
									g_module_snippet_clock[snippetName].push(localObject);
								}
							}
							else {
								for (j = 0, maxJ = localObject.length; j < maxJ; j += 1) {
									if ($.inArray(localObject[j], g_module_snippet_clock[snippetName]) === -1) {
										g_module_snippet_clock[snippetName].push(localObject[j]);
									}
								}
							}
						}
						if (localPeripheral !== null &&
							typeof localPeripheral[localId] !== 'undefined' &&
							typeof localPeripheral[localId][val[localId]] !== 'undefined') {
							if (typeof g_module_snippet_peripheral[snippetName] === 'undefined') {
								g_module_snippet_peripheral[snippetName] = [];
							}
							localObject = localPeripheral[localId][val[localId]];
							if (!Array.isArray(localObject)) {
								if ($.inArray(localObject, g_module_snippet_peripheral[snippetName]) === -1) {
									g_module_snippet_peripheral[snippetName].push(localObject);
								}
							}
							else {
								for (j = 0, maxJ = localObject.length; j < maxJ; j += 1) {
									if ($.inArray(localObject[j], g_module_snippet_peripheral[snippetName]) === -1) {
										g_module_snippet_peripheral[snippetName].push(localObject[j]);
									}
								}
							}
						}

						if (val[localId].toString().indexOf(',') === -1) {
							localValue = val[localId].toString().trim();
						}
						else {
							localValue = '[' + val[localId].toString().replace(/,/g, ", ").trim() + ']';
						}
						newUpdatedSnippetFile = replaceTag(newUpdatedSnippetFile, localId, localValue, 'data:');

						if (localId.toString().toLowerCase().indexOf('textonly') === -1) {
							localValue = val[localId].toString().replace(/,/g, "|").trim();
						}
						else {
							localValue = "NUC_NULL";
						}
						newUpdatedSnippetCode = replaceTag(newUpdatedSnippetCode, localId, localValue, 'entireTag');
						g_object.peripheral[localId] = val[localId].toString().trim();
					}
					else {
						tagIds1 = getPropertyNames(val[localId]);
						for (j = 0, maxJ = tagIds1.length; j < maxJ; j += 1) {
							localId1 = tagIds1[j];
							g_recordedIds[snippetName].push(localId1);

							if (localPin !== null &&
								typeof localPin[localId1] !== 'undefined' &&
								typeof localPin[localId1][val[localId][localId1]] !== 'undefined') {
								if (typeof g_module_snippet_pin[snippetName] === 'undefined') {
									g_module_snippet_pin[snippetName] = [];
								}
								localObject = localPin[localId1][val[localId][localId1]];
								if (!Array.isArray(localObject)) {
									if ($.inArray(localObject, g_module_snippet_pin[snippetName]) === -1) {
										g_module_snippet_pin[snippetName].push(localObject);
									}
								}
								else {
									for (k = 0, maxK = localObject.length; k < maxK; k += 1) {
										if ($.inArray(localObject[k], g_module_snippet_pin[snippetName]) === -1) {
											g_module_snippet_pin[snippetName].push(localObject[k]);
										}
									}
								}
							}
							if (localClock !== null &&
								typeof localClock[localId1] !== 'undefined' &&
								typeof localClock[localId1][val[localId][localId1]] !== 'undefined') {
								if (typeof g_module_snippet_clock[snippetName] === 'undefined') {
									g_module_snippet_clock[snippetName] = [];
								}
								localObject = localClock[localId1][val[localId][localId1]];
								if (!Array.isArray(localObject)) {
									if ($.inArray(localObject, g_module_snippet_clock[snippetName]) === -1) {
										g_module_snippet_clock[snippetName].push(localObject);
									}
								}
								else {
									for (k = 0, maxK = localObject.length; k < maxK; k += 1) {
										if ($.inArray(localObject[k], g_module_snippet_clock[snippetName]) === -1) {
											g_module_snippet_clock[snippetName].push(localObject[k]);
										}
									}
								}
							}
							if (localPeripheral !== null &&
								typeof localPeripheral[localId1] !== 'undefined' &&
								typeof localPeripheral[localId1][val[localId][localId1]] !== 'undefined') {
								if (typeof g_module_snippet_peripheral[snippetName] === 'undefined') {
									g_module_snippet_peripheral[snippetName] = [];
								}
								localObject = localPeripheral[localId1][val[localId][localId1]];
								if (!Array.isArray(localObject)) {
									if ($.inArray(localObject, g_module_snippet_peripheral[snippetName]) === -1) {
										g_module_snippet_peripheral[snippetName].push(localObject);
									}
								}
								else {
									for (k = 0, maxK = localObject.length; k < maxK; k += 1) {
										if ($.inArray(localObject[k], g_module_snippet_peripheral[snippetName]) === -1) {
											g_module_snippet_peripheral[snippetName].push(localObject[k]);
										}
									}
								}
							}

							if (val[localId][localId1].toString().indexOf(',') === -1) {
								localValue = val[localId][localId1].toString().trim();
							}
							else {
								localValue = '[' + val[localId][localId1].toString().replace(/,/g, ", ").trim() + ']';
							}
							newUpdatedSnippetFile = replaceTag(newUpdatedSnippetFile, localId1, localValue, 'data:');

							if (localId1.toString().toLowerCase().indexOf('textonly') === -1) {
								localValue = val[localId][localId1].toString().replace(/,/g, "|").trim();
							}
							else {
								localValue = "NUC_NULL";
							}
							newUpdatedSnippetCode = replaceTag(newUpdatedSnippetCode, localId1, localValue, 'entireTag');
							g_object.peripheral[localId1] = val[localId][localId1].toString().trim();
						}
					}
				}

				if (currentButtonTitle.indexOf("Continue") === -1) {
					f1();
				}
			}
			else {
				f1();
			}
		};

		postRender = function (control) {
			var k,
				maxK,
				k1,
				maxK1,
				f1,
				observer,
				observable,
				recordedObservables = [],
				recordedObservables1 = [];

			NUTOOL_PER.g_postRender_f1 = f1 = function (val, test_propertyId) {
				var m,
					m0,
					n,
					maxM,
					maxM0,
					maxN,
					observerArray = [],
					listenerProperties = [],
					listenerValArray = [],
					newValue = null;

				if (typeof val === 'undefined') {
					val = "NUC_NONE";
					//return;
				}
				if (!NUTOOL_PER.g_bFunctionalTesting) {
					observerArray = recordedObservables1[this.propertyId];
				}
				else if (typeof recordedObservables[test_propertyId] === 'undefined') {
					return;
				}
				else {
					observerArray = recordedObservables[test_propertyId];
				}

				for (m = 0, maxM = local_perControls.length; m < maxM; m += 1) {
					for (m0 = 0, maxM0 = observerArray.length; m0 < maxM0; m0 += 1) {
						if (local_perControls[m].id === observerArray[m0]) {
							listenerProperties = getPropertyNames(local_perControls[m].listener);
							for (n = 0, maxN = listenerProperties.length; n < maxN; n += 1) {
								listenerValArray = listenerProperties[n].replace(/\s/g, '').split(',');
								if (listenerValArray.toString() === val.toString() ||
									(listenerValArray.toString() === "NUC_ANY" && val !== "NUC_NONE")) {
									newValue = local_perControls[m].listener[listenerProperties[n]];
									if (newValue.indexOf(',') !== -1) {
										newValue = newValue.replace(/\s/g, '');
										if (newValue.indexOf('[') === 0) {
											newValue = newValue.slice(1);
										}
										if (newValue.lastIndexOf(']') + 1 === newValue.length) {
											newValue = newValue.slicePriorToLastX(']');
										}
									}
									if (typeof local_perControls[m].groupId !== 'undefined' &&
										local_perControls[m].groupId !== 'none' &&
										local_perControls[m].groupId !== '') {
										observer = control.childrenByPropertyId[local_perControls[m].groupId].childrenByPropertyId[local_perControls[m].id];
										observer.setValue(newValue);
										observer.refresh();

									}
									else {
										observer = control.childrenByPropertyId[local_perControls[m].id];
										observer.setValue(newValue);
										observer.refresh();
									}
									break;
								}
							}
							break;
						}
					}
				}
			};

			NUTOOL_PER.g_postRender_control = control;
			if (control.options.form.buttons.submit.title === "Continue" ||
				!g_bDevelopingTool) {
				control.form.getButtonEl('submit').hide();
			}
			if (control.options.form.buttons.submit.title !== "Continue") {
				control.form.getButtonEl('submit').click();
			}
			// some controls needs to render again because of dependencies.
			// control.form.topControl.refresh(function() {
			// //$("#" + control.options.form.buttons.submit.id).show();
			// });

			// Continue to build a form if exists
			g_alpacaFormIndex = g_alpacaFormIndex + 1;
			if (g_alpacaFormRepository.length > 0 &&
				g_alpacaFormIndex < g_alpacaFormRepository.length) {
				$(g_alpacaFormRepository[g_alpacaFormIndex].holder).alpaca(g_alpacaFormRepository[g_alpacaFormIndex]);
			}
			// else {
			// control.form.getButtonEl('submit').click();
			// }

			for (k = 0, maxK = local_perControls.length; k < maxK; k += 1) {
				if (typeof local_perControls[k].observable !== 'undefined' &&
					local_perControls[k].observable !== 'none' &&
					local_perControls[k].observable !== '') {
					try {
						if (typeof local_perControls[k].groupId !== 'undefined' &&
							local_perControls[k].groupId !== 'none' &&
							local_perControls[k].groupId !== '') {
							observer = control.childrenByPropertyId[local_perControls[k].groupId].childrenByPropertyId[local_perControls[k].id];
						}
						else {
							observer = control.childrenByPropertyId[local_perControls[k].id];
						}
					}
					catch (err) {/*something wrong*/ }
					for (k1 = 0, maxK1 = local_perControls.length; k1 < maxK1; k1 += 1) {
						try {
							if (local_perControls[k1].id === local_perControls[k].observable) {
								if (typeof local_perControls[k1].groupId !== 'undefined' &&
									local_perControls[k1].groupId !== 'none' &&
									local_perControls[k1].groupId !== '') {
									observable = control.childrenByPropertyId[local_perControls[k1].groupId].childrenByPropertyId[local_perControls[k].observable];
								}
								else {
									observable = control.childrenByPropertyId[local_perControls[k].observable];
								}
								break;
							}

						}
						catch (err) {/*something wrong*/ }
					}
					if (typeof observer !== 'undefined' && typeof observable !== 'undefined') {
						observer.subscribe(observable, f1);
						if (typeof recordedObservables[local_perControls[k].observable] === 'undefined') {
							recordedObservables[local_perControls[k].observable] = [];
						}
						recordedObservables[local_perControls[k].observable].push(local_perControls[k].id);
					}
				}
			}
			for (observable in recordedObservables) {
				if (recordedObservables.hasOwnProperty(observable)) {
					recordedObservables1[recordedObservables[observable][0]] = recordedObservables[observable];
				}
			}
		};
		/////////////////////////////////////////////// preceding procedure ////////////////////////////////////////////
		if (NUTOOL_PER.g_bFunctionalTesting) {
			alpacaControlEvents = function () { };
		}
		else {
			alpacaControlEvents = function () {
				var c,
					c1,
					maxC,
					maxC1,
					bUpdated = false,
					changeEvent,
					data,
					snippet,
					tagId,
					val;

				if (this.getValue() !== null) {
					data = this.getValue().toString().replace(/,/g, ", ").trim();
				}
				else {
					data = "";
				}

				g_enabledPeripheralFunctionData = {};
				for (c = 0, maxC = local_perControls.length; c < maxC; c += 1) {
					if (local_perControls[c].id === this.propertyId &&
						local_perControls[c].changeEvent !== 'undefined') {
						changeEvent = local_perControls[c].changeEvent;
						for (snippet in changeEvent) {
							if (changeEvent.hasOwnProperty(snippet) && snippet !== snippetName) {
								g_enabledPeripheralFunctionData[snippet] = {};
								for (tagId in changeEvent[snippet]) {
									if (changeEvent[snippet].hasOwnProperty(tagId)) {
										if (typeof changeEvent[snippet][tagId][data] !== 'undefined') {
											bUpdated = true;
											g_enabledPeripheralFunctionData[snippet][tagId] = changeEvent[snippet][tagId][data];
										}
										else if (data !== "") {
											for (val in changeEvent[snippet][tagId]) {
												if (changeEvent[snippet][tagId].hasOwnProperty(val) &&
													val === "NUC_ANY") {
													bUpdated = true;
													g_enabledPeripheralFunctionData[snippet][tagId] = changeEvent[snippet][tagId].NUC_ANY;
													break;
												}
											}
										}
										else if (data === "") {
											for (val in changeEvent[snippet][tagId]) {
												if (changeEvent[snippet][tagId].hasOwnProperty(val) &&
													val === "NUC_NONE") {
													bUpdated = true;
													g_enabledPeripheralFunctionData[snippet][tagId] = changeEvent[snippet][tagId].NUC_NONE;
													break;
												}
											}
										}
									}
								}
								if (bUpdated) {
									preprocessTagFile(snippet, 'updateData');
									preprocessTagFile(snippet, 'updateDataOfObservable');
									delete g_module_snippet_code[snippet];
									// remove the previous g_field1SubDIVsCache[snippet] to build one with new tag file
									if (typeof g_field1SubDIVsCache[snippet] !== 'undefined') {
										for (c1 = 0, maxC1 = g_field1SubDIVsCache[snippet].length; c1 < maxC1; c1 += 1) {
											if (typeof ($("#" + g_field1SubDIVsCache[snippet][c1])) !== 'undefined' &&
												$("#" + g_field1SubDIVsCache[snippet][c1]).alpaca("exists")) {
												if (!g_bReadyForRelease && window.console) { window.console.log("In alpacaControlEvents, remove: " + g_field1SubDIVsCache[snippet][c1]); }
												$("#" + g_field1SubDIVsCache[snippet][c1]).alpaca("destroy");
												$("#" + g_field1SubDIVsCache[snippet][c1]).remove();
											}
										}
										delete g_field1SubDIVsCache[snippet];
									}
								}
							}
						}
					}
				}
				if ($("#" + g_lastCheckedSnippetNode).hasClass('jstree-checked') &&
					$("#" + g_module_snippet_buttonId[g_lastCheckedSnippetNode.slicePriorToX('_PeripheralConfigure')]).alpaca("exists")) {
					$("#" + g_module_snippet_buttonId[g_lastCheckedSnippetNode.slicePriorToX('_PeripheralConfigure')]).alpaca("get").form.getButtonEl("submit").click();
				}
			};
		}
		if (typeof NUTOOL_PIN !== 'undefined') {
			precedingPath = 'PeripheralConfigure//';
		}
		readSnippetFilePath = precedingPath + g_chipType + '//' + snippetName + '.txt';
		if (NUTOOL_PER.g_bFunctionalTesting) {
			subDivBase = 10000000;
		}
		else {
			decideSubDivBase('groupId');
			decideSubDivBase('observable');
			decideSubDivBase('dependencies');
		}
		subDivCount = Math.ceil(local_perControls.length / subDivBase);
		if (!g_bReadyForRelease && window.console) { window.console.log("In buildAlpaca, subDivBase: " + subDivBase); }

		$("#field1_canvas").remove();
		$("#field1_anchor").remove();
		for (i = 0, max = g_field1SubDIVs.length; i < max; i += 1) {
			if (typeof ($("#" + g_field1SubDIVs[i])) !== 'undefined') {
				$("#" + g_field1SubDIVs[i]).hide();
			}
		}
		g_alpacaFormIndex = 0;
		g_alpacaFormRepository = [];
		/////////////////////////////////////////////// create sub DIVs ///////////////////////////////////////////////
		g_field1SubDIVsCache[snippetName] = [];
		for (i = 0, max = subDivCount; i < max; i += 1, g_field1SubIndex += 1) {
			$("#field1").append('<div id="field1_sub' + g_field1SubIndex + '"></div>');
			g_field1SubDIVs.push("field1_sub" + g_field1SubIndex);
			g_field1SubDIVsCache[snippetName].push("field1_sub" + g_field1SubIndex);
			if (!g_bReadyForRelease && window.console) { window.console.log("In buildAlpaca, g_field1SubDIVsCache[" + snippetName + "].push: field1_sub" + g_field1SubIndex); }

			if ((i + 1) * subDivBase < local_perControls.length) {
				maxJ = (i + 1) * subDivBase;
			}
			else {
				maxJ = local_perControls.length;
			}
			/////////////////////////////////////////////// alpaca->data //////////////////////////////////////////////////
			alpacaForm = {};
			alpacaForm.data = {};
			for (j = i * subDivBase; j < maxJ; j += 1) {
				localControl = local_perControls[j];
				if (typeof localControl.data !== 'undefined') {
					localFieldId = localControl.id;
					if (typeof localControl.groupId !== 'undefined' &&
						localControl.groupId !== 'none' &&
						localControl.groupId !== '') {
						localGroupId = localControl.groupId;
						if (!alpacaForm.data.hasOwnProperty(localGroupId)) {
							alpacaForm.data[localGroupId] = {};
						}
						alpacaForm.data[localGroupId][localFieldId] = localControl.data;
					}
					else {
						alpacaForm.data[localFieldId] = localControl.data;
					}
				}
			}
			/////////////////////////////////////////////// alpaca->schema ////////////////////////////////////////////////
			alpacaForm.schema = {};
			if (i === 0) {
				alpacaForm.schema.title = "Nuvoton Peripheral Configure";
				alpacaForm.schema.helper = "We can configure the IP details easily and correctly.";
			}
			alpacaForm.schema.type = "object";
			alpacaForm.schema.properties = {};
			for (j = i * subDivBase; j < maxJ; j += 1) {
				localControl = local_perControls[j];
				localFieldId = localControl.id;
				if (typeof localControl.type !== 'undefined') {
					localObject = {};
					localObject.id = localFieldId;
					if (localControl.type === "select" ||
						localControl.type === "radio") {
						localObject.type = "string";
						localObject.title = localControl.label;
						localObject.enum = localControl.enum;
					}
					else if (localControl.type === "multipleselect") {
						localObject.type = "string";
						localObject.title = localControl.label;
						localObject.enum = localControl.enum;
					}
					else if (localControl.type === "checkbox") {
						localObject.type = "string";
						if (typeof localControl.enum === 'undefined') {
							localControl.enum = [];
							localControl.enum.push(true);
						}
						if (typeof localControl.optionLabels === 'undefined') {
							localControl.optionLabels = [];
							localControl.optionLabels.push('<br>');
						}
						localObject.enum = localControl.enum;
						// localObject.items = {};
						// localObject.items.type = "string"
						// localObject.items.enum = localControl.enum;
					}
					else if (localControl.type === "checkboxBoolean") {
						localObject.type = "boolean";
					}
					else if (localControl.type === "integer") {
						if (localControl.minimum !== "none" &&
							localControl.minimum !== "") {
							localObject.minimum = localControl.minimum;
						}
						if (localControl.maximum !== "none" &&
							localControl.maximum !== "") {
							localObject.maximum = localControl.maximum;
						}
					}
					else if (localControl.type === "hextext") {
						localObject.format = "ip-address";
						if (localControl.minimum !== "none" &&
							localControl.minimum !== "") {
							localObject.minimumHex = localControl.minimum;
						}
						if (localControl.maximum !== "none" &&
							localControl.maximum !== "") {
							localObject.maximumHex = localControl.maximum;
						}
					}
					else if (localControl.type === "textonly") {
						localObject.type = "string";
					}
					else if (localControl.type === "hidden") {
						localObject.type = "string";
					}
					else {
						if (!g_bReadyForRelease) { alert('error! In buildAlpaca.'); }
					}
					// for all types
					if (typeof (localControl.default) !== 'undefined') {
						localObject.default = localControl.default;
					}
					if (typeof (localControl.dependencies) !== 'undefined' &&
						localControl.dependencies !== "none" &&
						localControl.dependencies !== "" /*&&
						NUTOOL_PER.g_bFunctionalTesting === false*/) {
						localObject.dependencies = localControl.dependencies;
					}

					if (typeof localControl.groupId !== 'undefined' &&
						localControl.groupId !== 'none' &&
						localControl.groupId !== '') {
						localGroupId = localControl.groupId;
						if (!alpacaForm.schema.properties.hasOwnProperty(localGroupId)) {
							alpacaForm.schema.properties[localGroupId] = {};
							alpacaForm.schema.properties[localGroupId].type = "object";
							alpacaForm.schema.properties[localGroupId].properties = {};
							g_groupIds[snippetName].push(localGroupId);
						}
						alpacaForm.schema.properties[localGroupId].properties[localFieldId] = localObject;
					}
					else {
						alpacaForm.schema.properties[localFieldId] = localObject;
					}
				}
			}
			/////////////////////////////////////////////// alpaca->options /////////////////////////////////////////////////
			alpacaForm.options = {};
			alpacaForm.options.focus = ""; // prevent auto-focus
			//alpacaForm.options.collapsible = true;

			alpacaForm.options.fields = {};
			for (j = i * subDivBase; j < maxJ; j += 1) {
				localControl = local_perControls[j];
				localFieldId = localControl.id;
				if (typeof localControl.type !== 'undefined') {
					localObject = {};
					localObject.events = {};
					if (localControl.type === "select") {
						localObject.type = localControl.type;
						localObject.helper = localControl.helper;
						localObject.sort = (localControl.sort === "true");
						localObject.hideNone = true;
						localObject.optionLabels = localControl.optionLabels;
						localObject.events.change = alpacaControlEvents;
					}
					if (localControl.type === "radio") {
						localObject.type = localControl.type;
						localObject.helper = localControl.helper;
						localObject.sort = (localControl.sort === "true");
						localObject.hideNone = true;
						localObject.optionLabels = localControl.optionLabels;
						localObject.vertical = (localControl.vertical === "true");
						localObject.events.click = alpacaControlEvents;
					}
					else if (localControl.type === "checkbox") {
						localObject.type = localControl.type;
						localObject.label = localControl.label;
						localObject.helper = localControl.helper;
						if (typeof localControl.enum !== 'undefined' &&
							localControl.enum.length === 1 &&
							typeof localControl.optionLabels !== 'undefined' &&
							localControl.optionLabels.length === 1 &&
							localControl.optionLabels[0] === "") {
							localControl.optionLabels[0] = '<br>';
						}
						localObject.optionLabels = localControl.optionLabels;
						localObject.sort = (localControl.sort === "true");
						localObject.events.change = alpacaControlEvents;
					}
					else if (localControl.type === "checkboxBoolean") {
						localObject.type = "checkbox";
						localObject.rightLabel = localControl.label;
						localObject.helper = localControl.helper;
						localObject.events.change = alpacaControlEvents;
					}
					else if (localControl.type === "multipleselect") {
						localObject.type = "select";
						localObject.label = localControl.label;
						localObject.helper = localControl.helper;
						localObject.size = localControl.size;
						localObject.sort = (localControl.sort === "true");
						localObject.removeDefaultNone = true;
						localObject.validate = false;
						localObject.multiple = true;
						localObject.optionLabels = localControl.optionLabels;
						localObject.events.change = alpacaControlEvents;
					}
					else if (localControl.type === "integer") {
						localObject.type = localControl.type;
						localObject.label = localControl.label;
						localObject.helper = localControl.helper;
						if (typeof localControl.validate !== 'undefined') {
							localObject.validate = (localControl.validate === "true");
						}
						localObject.events.change = alpacaControlEvents;
					}
					else if (localControl.type === "hextext") {
						localObject.label = localControl.label;
						localObject.helper = localControl.helper;
						if (typeof localControl.validate !== 'undefined') {
							localObject.validate = (localControl.validate === "true");
						}
						localObject.events.change = alpacaControlEvents;
					}
					else if (localControl.type === "textonly") {
						localObject.type = "textarea";
						localObject.label = localControl.label;
						localObject.helper = localControl.helper;
						localObject.view = "bootstrap-display";
					}
					else if (localControl.type === "hidden") {
						localObject.type = localControl.type;
					}
					// for all types
					if (typeof (localControl.dependenciesOption) !== 'undefined' &&
						localControl.dependenciesOption !== "none" &&
						localControl.dependenciesOption !== "") {
						if (typeof localControl.dependenciesOption === 'string' || localControl.dependenciesOption instanceof String) {
							localObject.dependencies = {};
							localObject.dependencies[localControl.dependencies] = localControl.dependenciesOption;
						}
						else if (typeof localControl.dependenciesOption === 'object' && localControl.dependenciesOption instanceof Array) {
							localObject.dependencies = {};
							localObject.dependencies[localControl.dependencies] = localControl.dependenciesOption.toString();
						}
						else {
							localObject.dependencies = localControl.dependenciesOption;
						}
					}

					if (typeof localControl.groupId !== 'undefined' &&
						localControl.groupId !== 'none' &&
						localControl.groupId !== '') {
						localGroupId = localControl.groupId;
						if (!alpacaForm.options.fields.hasOwnProperty(localGroupId)) {
							alpacaForm.options.fields[localGroupId] = {};
							alpacaForm.options.fields[localGroupId].type = "object";
							alpacaForm.options.fields[localGroupId].label = localControl.groupName;
							alpacaForm.options.fields[localGroupId].fields = {};
						}
						alpacaForm.options.fields[localGroupId].fields[localFieldId] = localObject;
					}
					else {
						alpacaForm.options.fields[localFieldId] = localObject;
					}
				}
			}

			alpacaForm.options.form = {};
			// alpacaForm.options.form.attributes = {};
			// alpacaForm.options.form.attributes.action = "";
			// alpacaForm.options.form.attributes.method = "";
			alpacaForm.options.form.buttons = {};
			alpacaForm.options.form.buttons.submit = {};
			if (i != max - 1) {
				alpacaForm.options.form.buttons.submit.title = "Continue";
			}
			else {
				alpacaForm.options.form.buttons.submit.title = "Generate Code";
				g_module_snippet_buttonId[snippetName] = "field1_sub" + g_field1SubIndex;
			}
			alpacaForm.options.form.buttons.submit.click = generateCodeFunction;
			alpacaForm.options.form.buttons.submit.id = "field1_sub" + g_field1SubIndex;
			/////////////////////////////////////////////// alpaca->view /////////////////////////////////////////////////////
			// try {
			// if (typeof ($.ajax({ url: g_currentSnippetLayoutath, async: false }).responseText) !== 'undefined') {
			// alpacaForm.view = {};
			// alpacaForm.view.parent = "bootstrap-edit-horizontal";
			// alpacaForm.view.layout = {};
			// alpacaForm.view.layout.template = g_currentSnippetLayoutath;
			// }
			// }
			// catch (err) { return; }
			/////////////////////////////////////////////// alpaca->postRender ///////////////////////////////////////////////
			alpacaForm.postRender = postRender;
			////////////////////////////////////////////// alpaca->holder ////////////////////////////////////////////////////
			alpacaForm.holder = "#field1_sub" + g_field1SubIndex;
			////////////////////////////////////////////// initialization ////////////////////////////////////////////////////
			// if (typeof ($("#field1_sub" + i).alpaca) !== 'undefined' &&
			// $("#field1_sub" + i).alpaca.length !== 0 &&
			// $("#field1_sub" + i).alpaca("exists")) {
			// $("#field1_sub" + i).remove();alert(i)
			// }
			// $("#field1_sub" + i).empty();
			$("#canvas_Peripheral").hide();
			$("#GenerateCode_pre").empty();
			$("#GenerateCode_pre").hide();
			$('.prettyprinted').removeClass('prettyprinted');

			g_alpacaFormRepository.push(alpacaForm);
		} // end of for (i = 0, max = subDivCount; i < max; i += 1, g_field1SubIndex += 1) {

		if (g_alpacaFormRepository.length > 0) {
			$(g_alpacaFormRepository[0].holder).alpaca(g_alpacaFormRepository[0]);
			//$(g_alpacaFormRepository[0].holder).load('PSIO.html')
		}
	}

	function checkAlpacaReady() {
		var recordedUIlanguage,
			toastMessage;

		if (g_alpacaFormRepository.length > 0 &&
			g_alpacaFormIndex < g_alpacaFormRepository.length) {
			recordedUIlanguage = $.ajax({ url: "NuToolSetup.txt", async: false }).responseText;
			if (typeof (recordedUIlanguage) !== 'undefined' && recordedUIlanguage.indexOf('UIlanguage:') !== -1) {
				recordedUIlanguage = recordedUIlanguage.sliceAfterX('UIlanguage:');
				recordedUIlanguage = recordedUIlanguage.slicePriorToX('\r');
				if (recordedUIlanguage === "Simplified Chinese") {
					toastMessage = '本软件目前正在忙碌中。请稍后再试...';
				}
				else if (recordedUIlanguage === "Traditional Chinese") {
					toastMessage = '本軟件目前正在忙碌中。請稍後再試...';
				}
				else {
					toastMessage = 'The tool is currently busy. Please try again later...';
				}
			}
			else {
				toastMessage = 'The tool is currently busy. Please try again later...';
			}
			$.toast().reset('all');
			$.toast({
				text: toastMessage,
				icon: 'warning',
				position: 'mid-center'
			});
			return false;
		}
		else {
			return true;
		}
	}

	function preprocessTagFile(fileName, mode) {
		var i,
			j,
			max,
			maxJ,
			val,
			precedingPath = "",
			readSnippetFilePath,
			newReadSnippetFile,
			newControlConfig,
			newControl,
			tempString,
			tempString1,
			tempArray = [],
			perControls = [],
			whileCount = 0,
			whileCount1 = 0,
			whileCount2 = 0;

		if (typeof mode === 'undefined') {
			mode = 'updateDefault';
		}

		if (typeof NUTOOL_PIN !== 'undefined') {
			precedingPath = 'PeripheralConfigure//';
		}
		readSnippetFilePath = precedingPath + g_chipType + '//' + fileName + '.txt';

		// read the saved config file
		try {
			originalReadConfigFile = saved_newReadConfigFile = newReadSnippetFile = $.ajax({ url: readSnippetFilePath, async: false }).responseText.replace(/\r/g, "");
		}
		catch (err) { return; }

		newReadSnippetFile = newReadSnippetFile.replace(/\/\*[\s\S]*?\*\/|\/\/.*/g, '');
		while (newReadSnippetFile.indexOf('<!') !== -1) {
			newControlConfig = newReadSnippetFile.sliceBetweenXandX('<!', '!>').replace(/\r?\n|\r/g, '');
			newControl = {};
			whileCount1 = 0;
			while (newControlConfig.indexOf(';') !== -1) {
				tempString = newControlConfig.slicePriorToX(';').trim();
				tempString1 = "";
				tempString1 = tempString.sliceAfterX(':').trim();
				tempString = tempString.slicePriorToX(':').replace(/\s/g, '');

				if ((tempString === "id" || tempString === "default" || tempString === "data" ||
					tempString === "observable" || tempString === "listener") &&
					tempString1 !== "") {
					if (tempString1.indexOf('{') !== -1 && tempString1.indexOf('}') !== -1) {
						newControl[tempString] = JSON.parse(tempString1.replace(/'/g, '"').trim());
					}
					else if (tempString1.indexOf('[') === -1) {
						newControl[tempString] = tempString1.replace(/"/g, " ").trim();
					}
					else {
						if (tempString1.indexOf('"') === -1) {
							tempString1 = tempString1.sliceAfterX('[');
							tempArray = [];

							whileCount2 = 0;
							while (tempString1.indexOf(',') !== -1 || tempString1.indexOf(']') !== -1) {
								if (tempString1.indexOf(',') !== -1) {
									tempArray.push(tempString1.slicePriorToX(',').toString().trim());
									tempString1 = tempString1.sliceAfterX(',');
								}
								else {
									tempArray.push(tempString1.slicePriorToX(']').toString().trim());
									tempString1 = "";
								}

								if (whileCount2 > 2000) {
									break;
								}
								else {
									whileCount2 = whileCount2 + 1;
								}
							}
						}
						else {
							tempArray = JSON.parse(tempString1);
						}

						newControl[tempString] = tempArray;
					}
				}

				newControlConfig = newControlConfig.sliceAfterX(';');
				if (whileCount1 > 2000) {
					break;
				}
				else {
					whileCount1 = whileCount1 + 1;
				}
			}
			if (!$.isEmptyObject(newControl)) {
				perControls.push(newControl);
			}

			newReadSnippetFile = newReadSnippetFile.sliceAfterX('>');
			if (whileCount > 2000) {
				break;
			}
			else {
				whileCount = whileCount + 1;
			}
		}

		for (i = 0, max = perControls.length; i < max; i += 1) {
			if (mode === 'updateDefault' &&
				typeof perControls[i].observable !== 'undefined') {
				for (j = 0, maxJ = perControls.length; j < maxJ; j += 1) {
					if (perControls[j].id === perControls[i].observable &&
						typeof perControls[j].default !== 'undefined') {
						if (typeof perControls[i].listener[perControls[j].default] !== 'undefined') {
							saved_newReadConfigFile = replaceTag(saved_newReadConfigFile, perControls[i].id, perControls[i].listener[perControls[j].default], 'default:');
						}
						else if (perControls[j].default !== "") {
							for (val in perControls[i].listener) {
								if (perControls[i].listener.hasOwnProperty(val) &&
									val === "NUC_ANY") {
									saved_newReadConfigFile = replaceTag(saved_newReadConfigFile, perControls[i].id, perControls[i].listener.NUC_ANY, 'default:');
									break;
								}
							}
						}
					}
				}
			}
			if (mode === 'updateData') {
				if (typeof g_enabledPeripheralFunctionData[fileName] !== 'undefined' &&
					typeof g_enabledPeripheralFunctionData[fileName][perControls[i].id] !== 'undefined' &&
					perControls[i].id.toLowerCase().indexOf('textonly') === -1) {
					saved_newReadConfigFile = replaceTag(saved_newReadConfigFile, perControls[i].id, g_enabledPeripheralFunctionData[fileName][perControls[i].id], 'data:');
				}
			}
			if (mode === 'updateDataOfObservable' &&
				typeof perControls[i].observable !== 'undefined') {
				for (j = 0, maxJ = perControls.length; j < maxJ; j += 1) {
					if (perControls[j].id === perControls[i].observable &&
						typeof perControls[j].data !== 'undefined') {
						if (typeof perControls[i].listener[perControls[j].data] !== 'undefined') {
							saved_newReadConfigFile = replaceTag(saved_newReadConfigFile, perControls[i].id, perControls[i].listener[perControls[j].data], 'data:');
						}
						else if (perControls[j].data !== "") {
							for (val in perControls[i].listener) {
								if (perControls[i].listener.hasOwnProperty(val) &&
									val === "NUC_ANY") {
									saved_newReadConfigFile = replaceTag(saved_newReadConfigFile, perControls[i].id, perControls[i].listener.NUC_ANY, 'data:');
									break;
								}
							}
						}
					}
				}
			}
		}

		g_currentSnippetFilePath = readSnippetFilePath;
		g_updatedSnippetFile = saved_newReadConfigFile;
		if (saved_newReadConfigFile !== originalReadConfigFile) {
			try { external.updateSnippetFileFromJs(); } catch (err) { }
		}
		g_updatedSnippetFile = "";
	}

	function decidePerControls(filePath, fileName) {
		var readSnippetFilePath,
			newReadSnippetFile,
			newControlConfig,
			newControl,
			newControlName = g_partNumber_package.slicePriorToX('('),
			newControlType = g_partNumber_type,
			newControlFilter = {},
			newControlFilterExp,
			tempString,
			tempString1,
			tempArray = [],
			whileCount = 0,
			whileCount1 = 0,
			whileCount2 = 0,
			val,
			bfound,
			filterExp,
			filterExp1,
			realField,
			decideFieldFromFilter;

		decideFieldFromFilter = function (originalField, filter) {
			bfound = false;
			for (filterExp in originalField) {
				if (originalField.hasOwnProperty(filterExp)) {
					if (filterExp.indexOf('NUC_OR') === 0) {
						realField = [];
						for (filterExp1 in originalField[filterExp]) {
							if (originalField[filterExp].hasOwnProperty(filterExp1)) {
								try { newControlFilterExp = compileExpression(filterExp1); } catch (err) {
									if (!g_bReadyForRelease) { alert(filterExp1 + ' failed at compileExpression. Something was wrong in decideFieldFromFilter.'); }
								}
								if (newControlFilterExp(filter)) {
									bfound = true;
									realField.push(originalField[filterExp][filterExp1]);
								}
							}
						}
						if (bfound) {
							realField = realField.map(String);
							break; // leave for (filterExp in originalField) {
						}

					}
					else if (filterExp.indexOf('NUC_AND') === 0) {
						bfound = true;
						realField = [];
						for (filterExp1 in originalField[filterExp]) {
							if (originalField[filterExp].hasOwnProperty(filterExp1)) {
								try { newControlFilterExp = compileExpression(filterExp1); } catch (err) {
									if (!g_bReadyForRelease) { alert(filterExp1 + ' failed at compileExpression. Something was wrong in decideFieldFromFilter.'); }
								}
								if (newControlFilterExp(filter)) {
									realField.push(originalField[filterExp][filterExp1]);
								}
								else {
									bfound = false;
									realField = [];
									break; // for (filterExp1 in originalField[filterExp]) {
								}
							}
						}
						if (bfound) {
							realField = realField.map(String);
							break; // leave for (filterExp in originalField) {
						}
					}
					else {
						try { newControlFilterExp = compileExpression(filterExp); } catch (err) {
							if (!g_bReadyForRelease) { alert(filterExp + ' failed at compileExpression. Something was wrong in decideFieldFromFilter.'); }
						}
						if (newControlFilterExp(filter)) {
							bfound = true;
							realField = originalField[filterExp].map(String);
							break; // leave for (filterExp in originalField) {
						}
					}
				}
			}
			if (!bfound) {
				if (typeof originalField.NUC_ANY !== 'undefined') {
					realField = originalField.NUC_ANY.map(String);
				}
				else {
					realField = 'none';
				}
			}

			return realField;
		};

		readSnippetFilePath = filePath;
		// read the saved config file
		try {
			newReadSnippetFile = $.ajax({ url: readSnippetFilePath, async: false }).responseText.replace(/\r/g, "").replace(/\/\*[\s\S]*?\*\/|\/\/.*/g, '');
		}
		catch (err) { return; }

		g_groupIds[fileName] = [];
		g_recordedIds[fileName] = [];
		g_perControls[fileName] = [];
		while (newReadSnippetFile.indexOf('<!') !== -1) {
			newControlConfig = newReadSnippetFile.sliceBetweenXandX('<!', '!>').replace(/\r?\n|\r/g, '');
			newControl = {};
			whileCount1 = 0;
			while (newControlConfig.indexOf(';') !== -1) {
				tempString = newControlConfig.slicePriorToX(';').trim();
				tempString1 = tempString.sliceAfterX(':').trim();
				tempString = tempString.slicePriorToX(':').replace(/\s/g, '');

				if (tempString1.indexOf('{') !== -1 && tempString1.indexOf('}') !== -1) {
					newControl[tempString] = JSON.parse(tempString1.replace(/'/g, '"').trim());
				}
				else if (tempString1.indexOf('[') === -1) {
					if (tempString.indexOf('filterExp') === -1) {
						newControl[tempString] = tempString1.replace(/"/g, " ").trim();
					}
					else {
						newControl[tempString] = tempString1.trim();
					}
				}
				else {
					if (tempString1.indexOf('"') === -1) {
						tempString1 = tempString1.sliceAfterX('[');
						tempArray = [];

						whileCount2 = 0;
						while (tempString1.indexOf(',') !== -1 || tempString1.indexOf(']') !== -1) {
							if (tempString1.indexOf(',') !== -1) {
								tempArray.push(tempString1.slicePriorToX(',').toString().trim());
								tempString1 = tempString1.sliceAfterX(',');
							}
							else {
								tempArray.push(tempString1.slicePriorToX(']').toString().trim());
								tempString1 = "";
							}

							if (whileCount2 > 2000) {
								break;
							}
							else {
								whileCount2 = whileCount2 + 1;
							}
						}
					}
					else {
						tempArray = JSON.parse(tempString1);
					}

					newControl[tempString] = tempArray;
				}

				newControlConfig = newControlConfig.sliceAfterX(';');
				if (whileCount1 > 2000) {
					break;
				}
				else {
					whileCount1 = whileCount1 + 1;
				}
			}
			// filter out tags
			if (typeof newControl.filter !== 'undefined') {
				newControlFilter = newControl.filter;
			}
			if (typeof newControlFilter[newControlName] !== 'undefined') {
				if (typeof newControlFilter[newControlName] == "function") {
					newControlFilter = newControlFilter[newControlName]();
				}
				else {
					newControlFilter = newControlFilter[newControlName];
				}
			}
			else if (typeof newControlFilter[newControlType] !== 'undefined') {
				if (typeof newControlFilter[newControlType] == "function") {
					newControlFilter = newControlFilter[newControlType]();
				}
				else {
					newControlFilter = newControlFilter[newControlType];
				}
			}
			newControlFilter.name = newControlName;
			if (newControlType !== "") {
				newControlFilter.type = newControlType;
			}
			for (val in g_supportedGPIOPins) {
				if (g_supportedGPIOPins.hasOwnProperty(val)) {
					newControlFilter[val] = g_supportedGPIOPins[val];
				}
			}
			if (typeof newControl.filterExp !== 'undefined' &&
				newControl.filterExp !== 'none' &&
				newControl.filterExp !== '') {
				try { newControlFilterExp = compileExpression(newControl.filterExp); } catch (err) {
					if (!g_bReadyForRelease) { alert(newControl.id + ' failed at compileExpression. Something was wrong in filterExp.'); }
				}
				if (!newControlFilterExp(newControlFilter)) {
					newControl = {};
				}
			}

			if (!$.isEmptyObject(newControl)) {
				if (typeof newControl.default !== 'undefined' &&
					_.isObject(newControl.default) && !Array.isArray(newControl.default)) {
					newControl.default = decideFieldFromFilter(newControl.default, newControlFilter);
				}
				if (typeof newControl.enum !== 'undefined' &&
					_.isObject(newControl.enum) && !Array.isArray(newControl.enum)) {
					newControl.enum = decideFieldFromFilter(newControl.enum, newControlFilter);
				}
				if (typeof newControl.optionLabels !== 'undefined' &&
					_.isObject(newControl.optionLabels) && !Array.isArray(newControl.optionLabels)) {
					newControl.optionLabels = decideFieldFromFilter(newControl.optionLabels, newControlFilter);
				}

				g_perControls[fileName].push(newControl);
			}

			newReadSnippetFile = newReadSnippetFile.sliceAfterX('>');
			if (whileCount > 2000) {
				break;
			}
			else {
				whileCount = whileCount + 1;
			}
		}
		if (!g_bReadyForRelease && window.console) { window.console.log("In decidePerControls, g_perControls.length:" + g_perControls[fileName].length); }
	}

	function savePerControls(filePath) {
		var i,
			max,
			readSnippetFilePath,
			newReadSnippetFile,
			newControlConfig,
			tempString,
			tempString1,
			savedIds = [],
			tempArray = [],
			tempArray1 = [],
			tempObject = {},
			whileCount = 0,
			whileCount1 = 0;

		readSnippetFilePath = filePath;
		// read the saved config file
		try {
			newReadSnippetFile = $.ajax({ url: readSnippetFilePath, async: false }).responseText.replace(/\r/g, "").replace(/\/\*[\s\S]*?\*\/|\/\/.*/g, '');
		}
		catch (err) { return; }
		while (newReadSnippetFile.indexOf('<!') !== -1) {
			newControlConfig = newReadSnippetFile.sliceBetweenXandX('<!', '!>').replace(/\r?\n|\r/g, '');
			if (newControlConfig.indexOf('data') !== -1) {
				whileCount1 = 0;
				while (newControlConfig.indexOf(';') !== -1) {
					tempString = newControlConfig.slicePriorToX(';');
					tempString1 = "";
					tempString1 = tempString.sliceAfterX(':').trim();
					tempString = tempString.slicePriorToX(':').replace(/\s/g, '');

					if (tempString === "id") {
						if (savedIds.indexOf(tempString1) === -1) {
							tempArray.push(tempString1);
							savedIds.push(tempString1);
						}
						else {
							break;
						}
					}
					if (tempString === "data") {
						tempArray1.push(tempString1);
						break;
					}

					newControlConfig = newControlConfig.sliceAfterX(';');
					if (whileCount1 > 2000) {
						break;
					}
					else {
						whileCount1 = whileCount1 + 1;
					}
				}
			}

			newReadSnippetFile = newReadSnippetFile.sliceAfterX('>');
			if (whileCount > 2000) {
				break;
			}
			else {
				whileCount = whileCount + 1;
			}
		}
		// populate the tempObject
		for (i = 0, max = tempArray.length; i < max; i += 1) {
			tempObject[tempArray[i]] = tempArray1[i];
		}

		return tempObject;
	}

	function restorePerControlsToDefault(filePath) {
		var i,
			max,
			readSnippetFilePath,
			newReadSnippetFile,
			saved_newReadConfigFile,
			originalReadConfigFile,
			fileName = filePath.sliceAfterX('//').sliceBetweenXandX('//', '.txt'),
			newControlConfig,
			tempString,
			tempString1,
			tempArray = [],
			tempArray1 = [],
			whileCount = 0,
			whileCount1 = 0;

		readSnippetFilePath = filePath;
		// read the saved config file
		try {
			originalReadConfigFile = saved_newReadConfigFile = newReadSnippetFile = $.ajax({ url: readSnippetFilePath, async: false }).responseText.replace(/\r/g, "");
		}
		catch (err) { return; }

		newReadSnippetFile = newReadSnippetFile.replace(/\/\*[\s\S]*?\*\/|\/\/.*/g, '');
		while (newReadSnippetFile.indexOf('<!') !== -1) {
			newControlConfig = newReadSnippetFile.sliceBetweenXandX('<!', '!>').replace(/\r?\n|\r/g, '');
			if (newControlConfig.indexOf('default') !== -1) {
				whileCount1 = 0;
				while (newControlConfig.indexOf(';') !== -1) {
					tempString = newControlConfig.slicePriorToX(';');
					tempString1 = "";
					tempString1 = tempString.sliceAfterX(':').trim();
					tempString = tempString.slicePriorToX(':').replace(/\s/g, '');

					if (tempString === "id") {
						tempArray.push(tempString1);
					}
					if (tempString === "default") {
						if (typeof g_perControls[fileName] !== 'undefined' &&
							tempString1.indexOf('{') !== -1 && tempString1.indexOf('}') !== -1) {
							for (i = 0, max = g_perControls[fileName].length; i < max; i += 1) {
								if (g_perControls[fileName][i].id === tempArray[tempArray.length - 1]) {
									tempString1 = g_perControls[fileName][i].default;
									break;
								}
							}
						}
						tempArray1.push(tempString1);
						break;
					}

					newControlConfig = newControlConfig.sliceAfterX(';');
					if (whileCount1 > 2000) {
						break;
					}
					else {
						whileCount1 = whileCount1 + 1;
					}
				}
			}

			newReadSnippetFile = newReadSnippetFile.sliceAfterX('>');
			if (whileCount > 2000) {
				break;
			}
			else {
				whileCount = whileCount + 1;
			}
		}

		// replace the data field with the default field
		for (i = 0, max = tempArray.length; i < max; i += 1) {
			if (typeof tempArray1[i] !== 'undefined' && tempArray1[i].indexOf('{') === -1 && tempArray1[i].indexOf('}') === -1) {
				saved_newReadConfigFile = replaceTag(saved_newReadConfigFile, tempArray[i], tempArray1[i], 'data:');
			}
		}

		g_currentSnippetFilePath = readSnippetFilePath;
		g_updatedSnippetFile = saved_newReadConfigFile;
		if (g_updatedSnippetFile !== originalReadConfigFile) {
			try { external.updateSnippetFileFromJs(); } catch (err) { }
		}
		g_updatedSnippetFile = "";
	}

	function replaceTag(originalString, TagId, TagValue, whichField) {
		var returnValue,
			indexBegin,
			count = 0,
			indexEnd = -1,
			startIndex = 0,
			startIndex1 = 0,
			startTokenStr = '<!id:',
			endTokenStr = '!>',
			index,
			tempString = "",
			tempString1 = "";
		// standalone tags
		do {
			count++;
			indexBegin = originalString.indexOf(startTokenStr + TagId + ';', startIndex);
			if (indexBegin !== -1) {
				indexEnd = -1;
				startIndex1 = 0;
				while ((index = originalString.indexOf(endTokenStr, startIndex1)) > -1) {
					if (index > indexBegin) {
						indexEnd = index;
						break;
					}
					startIndex1 = index + 1;
				}

				if (indexEnd !== -1) {
					if (whichField === 'entireTag') {
						// update the entire tag
						if (TagValue === "") {
							//TagValue = '0';
						}
						else if (TagValue === "NUC_NULL") {
							TagValue = '';
						}
						else if (TagValue.toString().toLowerCase() === "true") {
							TagValue = "1";
						}
						else if (TagValue.toString().toLowerCase() === "false") {
							TagValue = "0";
						}

						returnValue = originalString.slice(0, indexBegin) + TagValue + originalString.slice(indexEnd + endTokenStr.length);
						break;
					}
					else {
						tempString = originalString.slice(indexBegin, indexEnd + endTokenStr.length);

						index = tempString.indexOf(whichField);
						if (index !== -1) {
							tempString1 = tempString.slice(index + whichField.length).sliceAfterX(';');
							tempString = tempString.slice(0, index + whichField.length);
							returnValue = originalString.slice(0, indexBegin) + tempString + TagValue + ';' + tempString1 + originalString.slice(indexEnd + endTokenStr.length);
						}
						else {
							// for controls which do not have the specific field to update
							returnValue = originalString;
						}
					}
					// search next tags which have the same id
					originalString = returnValue;
					startIndex = indexEnd + 1;
				}
				else {
					returnValue = originalString;
					break;
				}
			}
			else {
				returnValue = originalString;
				break;
			}
		} while (count < 1000);

		return returnValue; // Note: the type of returned result will be Object, not String.
	}

	function removeAllTags(originalString) {
		var i,
			max,
			indexBegin = -1,
			indexEnd = -1,
			startIndex = 0,
			startTokenStr,
			endTokenStr,
			newControlConfig,
			tempString,
			tempString1,
			whileCount = 0,
			whileCount1 = 0,
			localDefault,
			startTokenStrArray = ['<!', '<#'],
			endTokenStrArray = ['!>', '##>'],
			index;

		for (i = 0, max = startTokenStrArray.length; i < max; i += 1) {
			startTokenStr = startTokenStrArray[i];
			endTokenStr = endTokenStrArray[i];

			whileCount = 0;
			while ((indexBegin = originalString.indexOf(startTokenStr)) !== -1) {
				indexEnd = -1;
				startIndex = 0;
				while ((index = originalString.indexOf(endTokenStr, startIndex)) > -1) {
					if (index > indexBegin) {
						indexEnd = index;
						break;
					}
					startIndex = index + 1;
				}

				if (indexEnd !== -1) {
					localDefault = "";
					newControlConfig = originalString.slice(indexBegin).sliceBetweenXandX('<!', '!>').replace(/\/\*[\s\S]*?\*\/|\/\/.*/g, '').replace(/\r?\n|\r/g, '');
					whileCount1 = 0;
					while (newControlConfig.indexOf(';') !== -1) {
						tempString = newControlConfig.slicePriorToX(';');
						tempString1 = "";
						tempString1 = tempString.sliceAfterX(':').trim();
						tempString = tempString.slicePriorToX(':').replace(/\s/g, '');
						if (tempString === "default") {
							localDefault = tempString1;
						}
						if (tempString === "filterDefault" &&
							tempString1.toString().toLowerCase() === "false") {
							localDefault = "";
							break;
						}

						newControlConfig = newControlConfig.sliceAfterX(';');
						if (whileCount1 > 2000) {
							break;
						}
						else {
							whileCount1 = whileCount1 + 1;
						}
					}
					localDefault = localDefault.replace(/\[/g, "").replace(/\]/g, "").replace(/,/g, "|").trim();
					originalString = originalString.slice(0, indexBegin) + localDefault + originalString.slice(indexEnd + endTokenStr.length);
				}

				if (whileCount > 2000) {
					break;
				}
				else {
					whileCount = whileCount + 1;
				}
			}
		}

		return originalString; // Note: the type of returned result will be Object, not String.
	}

	function decideNuToolSetup() {
		// [Workaround]
		g_Dialog_Width = 893; // when dpi is 100%
		g_Dialog_Height = 590;
		g_NUC_TreeView_Height = g_Dialog_Height - 16;
		g_NUC_TreeView_Width = 230;
		return;
		// determine the dialog's size
		var recordedDialogSize = $.ajax({ url: "NuToolSetup.txt", async: false }).responseText;

		if (typeof (recordedDialogSize) !== 'undefined' && recordedDialogSize.indexOf('DialogSize:') !== -1) {
			recordedDialogSize = recordedDialogSize.sliceAfterX('DialogSize:X_');
			g_Dialog_Width = parseInt(recordedDialogSize.slicePriorToX('Y_'), 10);
			g_Dialog_Height = parseInt(recordedDialogSize.sliceBetweenXandX('Y_', '\r'), 10);
		}
		else {
			g_Dialog_Width = 893; // when dpi is 100%
			g_Dialog_Height = 590;
		}

		g_NUC_TreeView_Height = g_Dialog_Height - 16;
		g_NUC_TreeView_Width = 230;
		// determine whether developing the tool or not
		if (typeof (recordedDialogSize) !== 'undefined' && recordedDialogSize.indexOf('DevelopingTool:') !== -1) {
			recordedDialogSize = recordedDialogSize.sliceAfterX('DevelopingTool:').slicePriorToX('\r');
			if (recordedDialogSize.toString().toLowerCase().indexOf('yes') !== -1) {
				g_bDevelopingTool = true;
			}
		}

		recordedDialogSize = null;
	}

	function checkNodesInThirdPartyLibTree() {
		var i,
			max;

		for (i = 0, max = g_enabledThirdPartyLibNodes.length; i < max; i += 1) {
			$('#thirdPartyLibTree').jstree("check_node", $('#' + g_enabledThirdPartyLibNodes[i].replaceSpecialCharacters() + '_PeripheralConfigure'));
		}
	}

	function checkNodesInPerFunctionTree() {
		var i,
			max;

		for (i = 0, max = g_enabledPeripheralFunctionNodes.length; i < max; i += 1) {
			preprocessTagFile(g_enabledPeripheralFunctionNodes[i], 'updateData');
			if (i !== max - 1) {
				if ($('#' + g_enabledPeripheralFunctionNodes[i].slicePriorToX('_').replaceSpecialCharacters() + '_PeripheralConfigure').find("li").length > 0) {
					$perFunctionTree.jstree("open_node", $('#' + g_enabledPeripheralFunctionNodes[i].slicePriorToX('_').replaceSpecialCharacters() + '_PeripheralConfigure'));
					$('#' + g_enabledPeripheralFunctionNodes[i].slicePriorToX('_').replaceSpecialCharacters() + '_PeripheralConfigure').removeClass('jstree-unchecked jstree-checked').addClass('jstree-undetermined');
				}
				$('#' + g_enabledPeripheralFunctionNodes[i].replaceSpecialCharacters() + '_PeripheralConfigure').removeClass('jstree-unchecked jstree-undetermined').addClass('jstree-checked');
			}
			else {
				$('#perFunctionTree').jstree("check_node", $('#' + g_enabledPeripheralFunctionNodes[i].replaceSpecialCharacters() + '_PeripheralConfigure'));
			}
		}
	}

	function readTreeContent(readConfigFile) {
		var treeContent,
			readConfigFileBackup = readConfigFile;
		if (readConfigFile !== "" && typeof (readConfigFile) !== 'undefined') {
			// read the tree of Third Party Libraries
			while (readConfigFile.indexOf('ThirdPartyLibs:') !== -1) {
				treeContent = readConfigFile.sliceAfterX('ThirdPartyLibs:').slicePriorToX('\r');
				g_enabledThirdPartyLibNodes = treeContent.split('/');
				// move to the next
				readConfigFile = treeContent.slice(1);
			}
			// read the tree of Peripheral Functions
			readConfigFile = readConfigFileBackup;
			while (readConfigFile.indexOf('PeripheralFunctions:') !== -1) {
				treeContent = readConfigFile.sliceAfterX('PeripheralFunctions:').slicePriorToX('\r');
				g_enabledPeripheralFunctionNodes = treeContent.split('/');
				// move to the next
				readConfigFile = treeContent.slice(1);
			}
			// read the data of Peripheral Functions
			readConfigFile = readConfigFileBackup;
			while (readConfigFile.indexOf('PeripheralFunctionData:') !== -1) {
				treeContent = readConfigFile.sliceAfterX('PeripheralFunctionData:').slicePriorToX('\r');
				if (treeContent.indexOf('{') !== -1) {
					g_enabledPeripheralFunctionData = JSON.parse(treeContent);
				}
				else {
					g_enabledPeripheralFunctionData = {};
				}
				// move to the next
				readConfigFile = treeContent.slice(1);
			}
		}
		// de-reference
		treeContent = null;
		readConfigFileBackup = null;
	}

	function decideHotKeys() {
		$(document).keypress(function (e) {
			switch (e.which) {
				case 122: //z
					break;
				case 120: //x
					break;
				case 99: // c
					//generateCodeFunctionByJS('PDMA_CH1')
					//ACMP BPWM0 BPWM1 CLK CRC CRYPTO *DAC *EADC
					//EBI_BANK0 EBI_BANK1 EBI_BANK2 FMC
					//GPIO_DB GPIO_PA GPIO_PB GPIO_PC GPIO_PD GPIO_PE GPIO_PF
					//I2C0 I2C1 OPA PDMA_CH0 PSIO PWM0_CH0CH1
					//QSPI *RTC SC0 SPII2S SYS TIMER0 UART0
					//USBD USCI0_I2C WDT WWDT

					//var xml = new XMLSerializer(),
					// var win = window.open("", "", "",false);
					// doc = win.document;
					// doc.open("text/plain");
					// //doc.write(xml.serializeToString($("#" + g_field1SubDIVs[0])[0]));
					// //doc.write($("#" + g_field1SubDIVs[0]).clone(true, true).html());
					// doc.write($("#field1").clone(true).html());
					// doc.close();

					//$('#CodeGeneratorContainer').html($("#field1").clone(true, true).html());

					// var win = window.open("", "", "",false);
					// doc = win.document;
					// doc.open("text/plain");
					// window.localStorage.setItem('stashed-event', JSON.stringify($("#field1")[0]))
					// doc.write(JSON.parse(window.localStorage.getItem('stashed-event')));
					// doc.close();
					break;
				case 113: // q
					break;
				case 119: // w
					break;
				case 13: // enter
					// the following should not be removed.
					g_bPressEnter = true;
					break;
				default:
					break;
			}
		});
	}

	function ce(type, ident, inner, isInput) {
		var el;
		if (!isInput) {
			el = document.createElement(type);
			el.innerHTML = inner;
		} else {
			el = document.createElement('input');
			el.value = inner;
			el.type = type;
		}
		el.id = ident;
		return el;
	}

	function removeAlldialogs() {
		if ($("#warningDialog").is(':visible')) {
			$("#warningDialog").dialog("destroy");
		}
		if ($("#warningForUncheckNodeDialog").is(':visible')) {
			$("#warningForUncheckNodeDialog").dialog("destroy");
		}
		if ($("#languageDialog").is(':visible')) {
			$("#languageDialog").dialog("destroy");
		}
		if ($('#generateCodeDialog').is(':visible')) {
			$('#generateCodeDialog').dialog("destroy");
		}
	}

	function createjscssfile(filename, filetype) {
		var fileref;
		if (filetype === "js") { //if filename is a external JavaScript file
			fileref = document.createElement('script');
			fileref.setAttribute("type", "text/javascript");
			fileref.setAttribute("src", filename);
		}
		else if (filetype === "css") { //if filename is an external CSS file
			fileref = document.createElement("link");
			fileref.setAttribute("rel", "stylesheet");
			fileref.setAttribute("type", "text/css");
			fileref.setAttribute("href", filename);
		}
		return fileref;
	}

	function replacejscssfile(oldfilename, newfilename, filetype, callback) {
		var i,
			targetelement = (filetype === "js") ? "script" : (filetype === "css") ? "link" : "none", //determine element type to create nodelist using
			targetattr = (filetype === "js") ? "src" : (filetype === "css") ? "href" : "none", //determine corresponding attribute to test for
			allsuspects = window.document.getElementsByTagName(targetelement),
			newelement = null;

		if (typeof NUTOOL_PIN !== 'undefined' && filetype === "js") {
			// Add the preceding path
			oldfilename = "PeripheralConfigure/" + oldfilename;
			newfilename = "PeripheralConfigure/" + newfilename;
		}

		if (newfilename !== "PeripheralConfigure/") {
			newelement = createjscssfile(newfilename, filetype);
			if (typeof callback === 'function') {
				newelement.onload = function () {
					callback();
				}
			};
		}

		if (!g_bReadyForRelease && window.console) { window.console.log("In replacejscssfile, oldfilename:" + oldfilename + " / newfilename:" + newfilename); }

		// To update the data in js file fresh, remove the matched files and add the new one.
		for (i = allsuspects.length; i >= 0; i -= 1) { //search backwards within nodelist for matching elements to remove
			if (allsuspects[i] && allsuspects[i].getAttribute(targetattr) !== null) {
				if (allsuspects[i].getAttribute(targetattr) === oldfilename) {
					allsuspects[i].parentNode.removeChild(allsuspects[i]);
				}
				else if (allsuspects[i].getAttribute(targetattr) === newfilename && newfilename !== '') {
					allsuspects[i].parentNode.removeChild(allsuspects[i]);
				}
			}
		}
		if (newelement !== null) {
			allsuspects[0].parentNode.appendChild(newelement);
		}
	}

	function buildMCUselect() {
		var i,
			max,
			$MCUselect = $('#MCUselect_Peripheral'),
			opt = {},
			mcuSelectArray = [],
			bCorrectpartNumber_package = false,
			previous_value = "",
			precedingPath = "";
		// remove all MCU selects then populate new ones.
		if ($MCUselect.children().length > 0) {
			$MCUselect.children().remove();
		}

		for (i = 0, max = NUTOOL_PER.g_cfg_chips.length; i < max; i += 1) {
			try {
				mcuSelectArray[mcuSelectArray.length] = NUTOOL_PER.g_cfg_chips[i].name + '(' + NUTOOL_PER.g_cfg_chips[i].pkg + ')';
			}
			catch (err) { }
		}
		mcuSelectArray.sort(natualSort);
		for (i = 0, max = mcuSelectArray.length; i < max; i += 1) {
			opt = document.createElement("option");
			opt.id = opt.innerHTML = opt.value = mcuSelectArray[i];
			$MCUselect[0].appendChild(opt);
		}
		// check if the g_partNumber_package is correct
		for (i = 0, max = NUTOOL_PER.g_cfg_chips.length; i < max; i += 1) {
			if (NUTOOL_PER.g_cfg_chips[i].name + '(' + NUTOOL_PER.g_cfg_chips[i].pkg + ')' === g_partNumber_package) {
				bCorrectpartNumber_package = true;
				break;
			}
		}

		if (!bCorrectpartNumber_package) {
			$MCUselect.val($("#MCUselect_Peripheral option:first-child").val()).change();
		}
		else {
			$MCUselect.val(g_partNumber_package);
		}

		$MCUselect.on('focus', function () {
			previous_value = this.value;
		}).on('change', function () {
			// prevent the user from generating wrong code
			if (!g_bAlpacaValidationResult) {
				if (typeof NUTOOL_PIN !== 'undefined') {
					precedingPath = 'PeripheralConfigure//';
				}
				$(this).val(previous_value);
				showWarningForFieldsInvalid(
					g_lastCheckedSnippetNode.slicePriorToX('_PeripheralConfigure'),
					function () {
						restorePerControlsToDefault(precedingPath + g_chipType + '//' + g_lastCheckedSnippetNode.slicePriorToX('_PeripheralConfigure') + '.txt');
						delete g_field1SubDIVsCache[g_lastCheckedSnippetNode.slicePriorToX('_PeripheralConfigure')];
						alpacaValidationSuccess();
						$('#perFunctionTree').jstree("uncheck_node", $('#' + g_lastCheckedSnippetNode));
					});
				return;
			}
			if (g_selectedPartNoValue !== $(this).val()) {
				g_selectedPartNoValue = $(this).val();
				// to prevent the select from hanging here due to invoking a big function, the function will be invoked immediately after this event is finished.
				setTimeout(afterMCUchange, 0);
			}
		});
		// de-reference
		i = null;
		max = null;
		mcuSelectArray = [];
		opt = null;
		bCorrectpartNumber_package = null;
		$MCUselect = null;
	}

	function afterMCUchange() {
		var oldChipType;
		//avoidClicking();
		if (g_selectedPartNoValue !== g_partNumber_package) {
			if (typeof NUTOOL_PIN !== 'undefined') {
				try {
					NUTOOL_PIN.setg_selectedPartNoValue(g_selectedPartNoValue);
					NUTOOL_CLOCK.setg_selectedPartNoValue(g_selectedPartNoValue);

					NUTOOL_PIN.loadPinConfigureTool_fromSelectionGuide();
					NUTOOL_CLOCK.loadClockConfigureTool_fromSelectionGuide();
				}
				catch (err) {
					if (!g_bReadyForRelease && window.console) { window.console.log("In afterMCUchange, NUTOOL_PIN/NUTOOL_CLOCK error."); }
				}
			}
			// to tackle the case of multiple usage of this app
			try { external.updateCurrentDialogSize(); } catch (err) { }

			oldChipType = g_chipType;
			g_chipType = decideNewChipType(g_selectedPartNoValue);
			// reload Content Js file to get the primitive NUTOOL_PER.g_cfg_gpios in case that it was modified
			replacejscssfile('NUC_' + oldChipType + '_Content.js', 'NUC_' + g_chipType + '_Content.js', 'js');

			// a new chip need not check nodes
			g_bCheckNodesBasedOnConfigFile = false;

			g_partNumber_package = g_selectedPartNoValue;
			initializeAll();
			NUTOOL_PER.g_readConfigFilePath = 'dummyPath';
			refresh();

			try { external.changeDialogCaptionFromJS('NuTool - CodeGenerator_' + NUTOOL_PER.g_toolVersion); } catch (err) { }
		}

		oldChipType = null;
	}

	function buildChipTypeSelect() {
		var i,
			max,
			opt,
			$ChipTypeSelect = $("#ChipTypeSelect_Peripheral"),
			previous_value = "",
			precedingPath = "";

		// restrict the width of the div of ChipType and MCU
		$('#ChipType_Peripheral')[0].setAttribute('style', 'background-color: #FFFFFF; width:' + (g_NUC_TreeView_Width - 16) + 'px; border-left: 8px solid #FFFFFF; border-right: 16px solid #F2F2F2; border-bottom: 5px solid #F2F2F2;');
		$('#MCU_Peripheral')[0].setAttribute('style', 'background-color: #FFFFFF; width:' + (g_NUC_TreeView_Width - 16) + 'px; border-left: 8px solid #FFFFFF; border-right: 16px solid #F2F2F2; border-bottom: 5px solid #F2F2F2;');

		for (i = 0, max = g_chipTypes.length; i < max; i += 1) {
			opt = document.createElement("option");
			// for IE8
			try {

				opt.id = opt.innerHTML = opt.value = g_chipTypes[i];
			}
			catch (err) { }
			$ChipTypeSelect[0].appendChild(opt);
		}
		$ChipTypeSelect.val(chipTypeToChipSeries(g_chipType));

		// build the corresponding MCU selects.
		buildMCUselect();

		$ChipTypeSelect.on('focus', function () {
			previous_value = this.value;
		}).on('change', function () {
			// prevent the user from generating wrong code
			if (!g_bAlpacaValidationResult) {
				if (typeof NUTOOL_PIN !== 'undefined') {
					precedingPath = 'PeripheralConfigure//';
				}
				$(this).val(previous_value);
				showWarningForFieldsInvalid(
					g_lastCheckedSnippetNode.slicePriorToX('_PeripheralConfigure'),
					function () {
						restorePerControlsToDefault(precedingPath + g_chipType + '//' + g_lastCheckedSnippetNode.slicePriorToX('_PeripheralConfigure') + '.txt');
						delete g_field1SubDIVsCache[g_lastCheckedSnippetNode.slicePriorToX('_PeripheralConfigure')];
						alpacaValidationSuccess();
						$('#perFunctionTree').jstree("uncheck_node", $('#' + g_lastCheckedSnippetNode));
					});
				return;
			}
			if (g_chipType != $(this).val()) {
				var oldfilename = 'NUC_' + g_chipType + '_Content.js';
				g_chipType = chipSeriesToChipType($(this).val());
				var newfilename = 'NUC_' + g_chipType + '_Content.js';
				replacejscssfile(oldfilename, newfilename, 'js', buildMCUselect);
			}
		});

		// de-reference
		i = null;
		max = null;
		opt = null;
		$ChipTypeSelect = null;
	}

	function decideNewChipType(newPartNumber_package) {
		var newChipType;

		// newPartNumber_package obtained from OpenOCD does not contain the package information
		if (newPartNumber_package.indexOf('(') === -1) {
			newPartNumber_package = newPartNumber_package + '(';
		}

		// decide chip type from part number name
		// the sequence is sensitive. do not disorder them.
		if (newPartNumber_package.indexOf('M0564') === 0) {
			newChipType = 'M0564';
		}
		else if (g_bDevelopingTool &&
			newPartNumber_package.indexOf('NUC122ZD2AN') === 0 ||
			newPartNumber_package.indexOf('NUC122ZC1AN') === 0 ||
			newPartNumber_package.indexOf('NUC122LD2AN') === 0) {
			newChipType = 'DEMO';
		}
		else if (newPartNumber_package.indexOf('M45') === 0 || newPartNumber_package.indexOf('M4TK') === 0) {
			newChipType = 'M451';
		}
		else if (newPartNumber_package.indexOf('M48') === 0) {
			newChipType = 'M480';
		}
		else if (newPartNumber_package.indexOf('M253') === 0) {
			newChipType = 'M253';
		}
		else if (newPartNumber_package.indexOf('M25') === 0) {
			newChipType = 'M251';
		}
		else if (newPartNumber_package.indexOf('M2351') === 0) {
			newChipType = 'M2351';
		}
		else if (newPartNumber_package.indexOf('M030G') === 0 ||
			newPartNumber_package.indexOf('M031G') === 0) {
			newChipType = 'M030GM031G';
		}
		else if (newPartNumber_package.indexOf('M030') === 0 ||
			newPartNumber_package.indexOf('M031') === 0 ||
			newPartNumber_package.indexOf('M032') === 0) {
			newChipType = 'M031';
		}
		else if (newPartNumber_package.indexOf('M0518') === 0) {
			newChipType = 'M0518';
		}
		else if (newPartNumber_package.indexOf('M0519') === 0) {
			newChipType = 'M0519';
		}
		else if (newPartNumber_package.indexOf('M05') === 0 && newPartNumber_package.indexOf('DN(') !== -1) {
			newChipType = 'M051DN';
		}
		else if (newPartNumber_package.indexOf('M05') === 0 && newPartNumber_package.indexOf('DE(') !== -1) {
			newChipType = 'M051DE';
		}
		else if (newPartNumber_package.indexOf('MHC54ZDN') === 0 || newPartNumber_package.indexOf('PL054TDN') === 0) {
			newChipType = 'M051DN';
		}
		else if (newPartNumber_package.indexOf('M05') === 0 && newPartNumber_package.indexOf('BN(') !== -1) {
			newChipType = 'M051BN';
		}
		else if (newPartNumber_package.indexOf('E32') === 0) {
			newChipType = 'M051BN';
		}
		else if (newPartNumber_package.indexOf('M058S') === 0) {
			newChipType = 'M058S';
		}
		else if (newPartNumber_package.indexOf('M05') === 0 && newPartNumber_package.indexOf('AN(') !== -1) {
			newChipType = 'M051AN';
		}
		else if (newPartNumber_package.indexOf('MINI58') === 0) {
			newChipType = 'MINI58';
		}
		else if (newPartNumber_package.indexOf('MINI5') === 0 && newPartNumber_package.indexOf('AN(') !== -1) {
			newChipType = 'MINI51AN';
		}
		else if ((newPartNumber_package.indexOf('MINI5') === 0 && newPartNumber_package.indexOf('AE(') !== -1) ||
			newPartNumber_package.indexOf('MINI54XFHC') === 0 ||
			newPartNumber_package.indexOf('MINI55') === 0 ||
			newPartNumber_package.indexOf('NVS06AL') === 0) {
			newChipType = 'MINI55';
		}
		else if ((newPartNumber_package.indexOf('MINI5') === 0 && newPartNumber_package.indexOf('DE(') !== -1) ||
			newPartNumber_package.indexOf('MINI54FHC') === 0) {
			newChipType = 'MINI51DE';
		}
		else if (newPartNumber_package.indexOf('NUC2') === 0 && newPartNumber_package.indexOf('AN(') !== -1) {
			newChipType = 'NUC200AN';
		}
		else if (newPartNumber_package.indexOf('NUC2') === 0 && newPartNumber_package.indexOf('AE(') !== -1) {
			newChipType = 'NUC200AE';
		}
		else if (newPartNumber_package.indexOf('NUC029') === 0 && newPartNumber_package.indexOf('AE(') !== -1) {
			newChipType = 'NUC029AE';
		}
		else if (newPartNumber_package.indexOf('NUC029') === 0 && newPartNumber_package.indexOf('AN(') !== -1) {
			newChipType = 'NUC029AN';
		}
		else if ((newPartNumber_package.indexOf('NANO120') === 0 || newPartNumber_package.indexOf('NANO100') === 0) &&
			newPartNumber_package.indexOf('AN(') !== -1) {
			newChipType = 'NANO100AN';
		}
		else if ((newPartNumber_package.indexOf('NANO100') === 0 || newPartNumber_package.indexOf('NANO110') === 0 || newPartNumber_package.indexOf('NANO120') === 0 || newPartNumber_package.indexOf('NANO130') === 0) &&
			newPartNumber_package.indexOf('BN(') !== -1) {
			newChipType = 'NANO100BN';
		}
		else if (newPartNumber_package.indexOf('NANO103') === 0 && newPartNumber_package.indexOf('AE(') !== -1) {
			newChipType = 'NANO103';
		}
		else if (newPartNumber_package.indexOf('NANO1') === 0 && newPartNumber_package.indexOf('AN(') !== -1) {
			newChipType = 'NANO112';
		}
		else if (newPartNumber_package.indexOf('NM11') === 0 || newPartNumber_package.indexOf('NM12') === 0) {
			newChipType = 'NM1200';
		}
		else if (newPartNumber_package.indexOf('NM15') === 0) {
			newChipType = 'NM1500';
		}
		else if (newPartNumber_package.indexOf('NUC121') === 0 || newPartNumber_package.indexOf('NUC125') === 0) {
			newChipType = 'NUC121AE';
		}
		else if (newPartNumber_package.indexOf('NUC122') === 0 && newPartNumber_package.indexOf('AN(') !== -1) {
			newChipType = 'NUC122AN';
		}
		else if (newPartNumber_package.indexOf('NUC123') === 0 &&
			(newPartNumber_package.indexOf('AE0(') !== -1 || newPartNumber_package.indexOf('AE1(') !== -1 ||
				newPartNumber_package.indexOf('AN0(') !== -1 || newPartNumber_package.indexOf('AN1(') !== -1)) {
			newChipType = 'NUC123AN_AE';
		}
		else if (newPartNumber_package.indexOf('NUC1') === 0 && newPartNumber_package.indexOf('AN(') !== -1) {
			newChipType = 'NUC100AN';
		}
		else if (newPartNumber_package.indexOf('NUC1') === 0 && newPartNumber_package.indexOf('BN(') !== -1) {
			newChipType = 'NUC100BN';
		}
		else if (newPartNumber_package.indexOf('NUC1') === 0 && newPartNumber_package.indexOf('CN(') !== -1) {
			newChipType = 'NUC100CN';
		}
		else if (newPartNumber_package.indexOf('NUC1') === 0 && newPartNumber_package.indexOf('DN(') !== -1) {
			newChipType = 'NUC100DN';
		}
		else if (newPartNumber_package.indexOf('NUC1262') === 0) {
			newChipType = 'NUC1262';
		}
		else if (newPartNumber_package.indexOf('NUC126') === 0) {
			newChipType = 'NUC126';
		}
		else if (newPartNumber_package.indexOf('NUC13') === 0) {
			newChipType = 'NUC131';
		}
		else if (newPartNumber_package.indexOf('NUC505') === 0) {
			newChipType = 'NUC505';
		}
		else if (newPartNumber_package.indexOf('I91') === 0) {
			newChipType = 'ISD9100';
		}
		else if (newPartNumber_package.indexOf('I93') === 0) {
			newChipType = 'ISD9300';
		}
		else {
			newChipType = 'NUC400';
		}
		return newChipType;
	}

	function decideNewPartNumberType(newPartNumber_package) {
		var newPartNumberType = "";

		for (i = 0, max = NUTOOL_PER.g_cfg_chips.length; i < max; i += 1) {
			if (NUTOOL_PER.g_cfg_chips[i].name + '(' + NUTOOL_PER.g_cfg_chips[i].pkg + ')' === newPartNumber_package &&
				typeof NUTOOL_PER.g_cfg_chips[i].type !== 'undefined') {
					newPartNumberType = NUTOOL_PER.g_cfg_chips[i].type;
				break;
			}
		}
		return newPartNumberType;
	}

	function chipSeriesToChipType(chipSeries) {
		var stringChipType;
		stringChipType = chipSeries;

		// it should match the first part number.
		if (chipSeries === "NUC200") {
			stringChipType = "NUC200AN";
		}
		else if (chipSeries === "NANO100") {
			stringChipType = "NANO100AN";
		}
		else if (chipSeries === "NUC100") {
			stringChipType = "NUC1262";
		}
		else if (chipSeries === "M030G") {
			stringChipType = "M030GM031G";
		}
		else if (chipSeries === "M031") {
			stringChipType = "M031";
		}
		else if (chipSeries === "M051") {
			stringChipType = "M051DE";
		}
		else if (chipSeries === "MINI51") {
			stringChipType = "MINI55";
		}
		else if (chipSeries === "NUC029") {
			stringChipType = "NUC029AE";
		}

		return stringChipType;
	}

	function chipTypeToChipSeries(chipType) {
		var stringChipSeries;
		stringChipSeries = chipType;

		if (chipType === "NUC200AN") {
			stringChipSeries = "NUC200";
		}
		else if (chipType === "NUC200AE") {
			stringChipSeries = "NUC200";
		}
		else if (chipType === "NANO100AN") {
			stringChipSeries = "NANO100";
		}
		else if (chipType === "NANO100BN") {
			stringChipSeries = "NANO100";
		}
		else if (chipType === "NANO103") {
			stringChipSeries = "NANO100";
		}
		else if (chipType === "NANO112") {
			stringChipSeries = "NANO100";
		}
		else if (chipType === "NUC100AN") {
			stringChipSeries = "NUC100";
		}
		else if (chipType === "NUC100BN") {
			stringChipSeries = "NUC100";
		}
		else if (chipType === "NUC100CN") {
			stringChipSeries = "NUC100";
		}
		else if (chipType === "NUC100DN") {
			stringChipSeries = "NUC100";
		}
		else if (chipType === "NUC131") {
			stringChipSeries = "NUC100";
		}
		else if (chipType === "NUC121AE") {
			stringChipSeries = "NUC100";
		}
		else if (chipType === "NUC123AN_AE") {
			stringChipSeries = "NUC100";
		}
		else if (chipType === "NUC122AN") {
			stringChipSeries = "NUC100";
		}
		else if (chipType.indexOf("NUC126") === 0) {
			stringChipSeries = "NUC100";
		}
		else if (chipType.indexOf("M030G") === 0) {
			stringChipSeries = "M030G";
		}
		else if (chipType.indexOf("M03") === 0) {
			stringChipSeries = "M031";
		}
		else if (chipType === "M051BN") {
			stringChipSeries = "M051";
		}
		else if (chipType === "M051DN") {
			stringChipSeries = "M051";
		}
		else if (chipType === "M051DE") {
			stringChipSeries = "M051";
		}
		else if (chipType === "M051AN") {
			stringChipSeries = "M051";
		}
		else if (chipType === "M058S") {
			stringChipSeries = "M051";
		}
		else if (chipType === "MINI51AN") {
			stringChipSeries = "MINI51";
		}
		else if (chipType === "MINI51DE") {
			stringChipSeries = "MINI51";
		}
		else if (chipType === "MINI55") {
			stringChipSeries = "MINI51";
		}
		else if (chipType === "MINI58") {
			stringChipSeries = "MINI51";
		}
		else if (chipType === "NUC029AE") {
			stringChipSeries = "NUC029";
		}
		else if (chipType === "NUC029AN") {
			stringChipSeries = "NUC029";
		}

		return stringChipSeries;
	}

	function clone(obj) {
		if (null === obj || "object" != typeof obj) return obj;
		var copy = obj.constructor();
		for (var attr in obj) {
			if (obj.hasOwnProperty(attr)) copy[attr] = clone(obj[attr]);
		}
		return copy;
	}

	function getPropertyNames(obj) {
		var propertyNames = [],
			index = 0,
			name;

		for (name in obj) {
			if (obj.hasOwnProperty(name)) {
				propertyNames[index] = name;
				index += 1;
			}
		}

		index = null;
		name = null;

		return propertyNames;
	}

	// case insensitive, digits to number interpolation
	function natualSort(as, bs) {
		var a, b, a1, b1, i = 0, L, rx = /(\d+)|(\D+)/g, rd = /\d/;
		if (isFinite(as) && isFinite(bs)) { return as - bs; }
		a = String(as).toLowerCase();
		b = String(bs).toLowerCase();
		if (a === b) { return 0; }
		if (!(rd.test(a) && rd.test(b))) { return a > b ? 1 : -1; }
		a = a.match(rx);
		b = b.match(rx);
		L = a.length > b.length ? b.length : a.length;
		while (i < L) {
			a1 = a[i];
			b1 = b[i];
			i += 1;
			if (a1 !== b1) {
				if (isFinite(a1) && isFinite(b1)) {
					if (a1.charAt(0) === "0") { a1 = "." + a1; }
					if (b1.charAt(0) === "0") { b1 = "." + b1; }
					return a1 - b1;
				}
				else { return a1 > b1 ? 1 : -1; }
			}
		}
		return a.length - b.length;
	}

	function determineIEversion() {
		var bLessThanOrEqualIE8 = false;

		// determine IE version
		if (jQuery.support.leadingWhitespace === false) {
			//code for IE6-IE8
			g_bLessThanOrEqualIE8 = true;
			g_unPrintedCharacters = '\u000C';
			// get context of canvas
			g_utility.getContext = function (element) {
				G_vmlCanvasManager.initElement(element);
				return element.getContext("2d");
			};
			// to complete release canvas node, this should call manually before remove.
			g_utility.removeContext = function ($id) {
				G_vmlCanvasManager.uninitElement($id[0]);
				$id.remove();
			};
			g_utility.addEvent = function (element, eventName, eventFunction) {
				if (typeof (element) !== 'undefined') {
					element.attachEvent("on" + eventName, eventFunction);
				}
			};
			g_utility.triggerEvent = function (id, eventName) {
				if (typeof ($(id)[0]) !== 'undefined') {
					$(id).trigger(eventName);
				}
			};
		}
		else {
			//code for IE9+
			g_bLessThanOrEqualIE8 = false;
			g_unPrintedCharacters = '\u000C';
			// get context of canvas
			g_utility.getContext = function (element) {
				return element.getContext("2d");
			};
			g_utility.removeContext = function ($id) {
				$id.remove();
			};
			g_utility.addEvent = function (element, eventName, eventFunction) {
				if (typeof (element) !== 'undefined') {
					element.addEventListener(eventName, eventFunction, false);
				}
			};
			g_utility.triggerEvent = function (id, eventName) {
				if (typeof ($(id)[0]) !== 'undefined') {
					$(id).trigger(eventName);
				}
			};
		}

		// invoke a dialog which tells that this tool does not support IE whose version is below 9.
		if ($('html').hasClass('ie8') || $('html').hasClass('ie7') || $('html').hasClass('ie6')) {
			bLessThanOrEqualIE8 = true;

			// JQuery sets the autofocus on the first input that is found. So play it sneaky by creating a "fake" input at the last line of your dialog
			$('<div id="belowIE9Dialog"><p>Please upgrade your IE to IE9 or higher version.<br />Otherwise, this tool will not run properly!</p><input type="text" size="1" style="position:relative;top:-5000px;"/></div>')
				.dialog({
					modal: true,
					title: 'Please update your IE!',
					width: 500,
					height: 'auto',
					show: 'fade',
					hide: 'fade',
					buttons: [
						{ text: "Cancel", click: function () { $(this).dialog("close"); } }
					]
				});
		}

		return bLessThanOrEqualIE8;
	}

	function versionCompare(v1, v2, options) {
		var lexicographical = options && options.lexicographical,
			zeroExtend = options && options.zeroExtend,
			v1parts = v1.split('.'),
			v2parts = v2.split('.');

		function isValidPart(x) {
			return (lexicographical ? /^\d+[A-Za-z]*$/ : /^\d+$/).test(x);
		}

		if (!v1parts.every(isValidPart) || !v2parts.every(isValidPart)) {
			return NaN;
		}

		if (zeroExtend) {
			while (v1parts.length < v2parts.length) v1parts.push("0");
			while (v2parts.length < v1parts.length) v2parts.push("0");
		}

		if (!lexicographical) {
			v1parts = v1parts.map(Number);
			v2parts = v2parts.map(Number);
		}

		for (var i = 0; i < v1parts.length; ++i) {
			if (v2parts.length == i) {
				return 1;
			}

			if (v1parts[i] == v2parts[i]) {
				continue;
			}
			else if (v1parts[i] > v2parts[i]) {
				return 1;
			}
			else {
				return -1;
			}
		}

		if (v1parts.length != v2parts.length) {
			return -1;
		}

		return 0;
	}

	function showAlertDialog(SimplifiedChinese, TraditionalChinese, English) {
		decideUIlanguage();
		if (g_userSelectUIlanguage === "Simplified Chinese") {
			alert(SimplifiedChinese);
		}
		else if (g_userSelectUIlanguage === "Traditional Chinese") {
			alert(TraditionalChinese);
		}
		else {
			alert(English);
		}
	}

	function decideChipTypeAndTreeContent() {
		var readConfigFilePath = "",
			saved_newReadConfigFile = "",
			newReadConfigFile = "",
			newPartNumber_package = "",
			newChipType = "",
			bResult = false,
			returnToDefaultCase = function () {
				g_chipType = 'M251'; // for the case the config.cfg is not existent.
				g_partNumber_package = "M251EC2AE(TSSOP28)";
			};

		// Add developing chip types
		if (g_bDevelopingTool) {
			for (i = 0, max = g_chipTypesDeveloping.length; i < max; i += 1) {
				g_chipTypes.push(g_chipTypesDeveloping[i]);
			}
		}

		g_readConfigFile = "";
		// assign a correct path of the config file
		if (NUTOOL_PER.g_readConfigFilePath === "") {
			readConfigFilePath = "Nu_config.cfg "; // the default path of auto-restore config file
		}
		else {
			readConfigFilePath = 'file:///' + NUTOOL_PER.g_readConfigFilePath;
		}
		// [Workaround]
		// saved_newReadConfigFile = newReadConfigFile = $.ajax({ url: readConfigFilePath, async: false }).responseText;
		// the read config file is empty or undefined. Restore to the default case.
		if (!newReadConfigFile || (/^\s*$/.test(newReadConfigFile))) {
			// default setting
			g_readConfigFile = newReadConfigFile;
			returnToDefaultCase();

			return bResult;
		}
		else {
			// find the '\r' pertaining to 'MCU:'
			while (newReadConfigFile.indexOf('\r') !== -1 && (newReadConfigFile.indexOf('\r') < newReadConfigFile.indexOf('MCU:'))) {
				newReadConfigFile = newReadConfigFile.sliceAfterX('\r');
			}

			newPartNumber_package = newReadConfigFile.sliceBetweenXandX('MCU:', '\r');
		}

		newChipType = decideNewChipType(newPartNumber_package);

		//check if newChipType is correct
		if ($.inArray(chipTypeToChipSeries(newChipType), g_chipTypes) === -1) {
			showAlertDialog("从配置档读出的晶片型号 " + newChipType + " 不正确。",
				"從配置檔讀出的晶片型號 " + newChipType + " 不正確。",
				"The chip type of " + newChipType + " read from the config file is incorrect.");

			returnToDefaultCase();

			return bResult;
		}

		// reload the corresponding chip content
		if (typeof (g_chipType) !== 'undefined' && g_chipType !== "") {
			oldfilename = 'NUC_' + g_chipType + '_Content.js';
			newfilename = 'NUC_' + newChipType + '_Content.js';

			replacejscssfile(oldfilename, newfilename, 'js');
		}
		else {
			oldfilename = 'NUC_M251_Content.js';
			newfilename = 'NUC_' + newChipType + '_Content.js';

			replacejscssfile(oldfilename, newfilename, 'js');
		}

		// get g_readConfigFile
		g_readConfigFile = newReadConfigFile;
		// get g_chipType
		g_chipType = newChipType;
		// update ChipTypeSelect
		$("#ChipTypeSelect_Peripheral").val(chipTypeToChipSeries(g_chipType));

		// get g_partNumber_package
		g_partNumber_package = newPartNumber_package;

		readTreeContent(g_readConfigFile);
		bResult = true;

		return bResult;
	}

	function initializeAll() {
		var i,
			max,
			$field1 = $("#field1");

		if (!g_bReadyForRelease && window.console) { window.console.log("Inside initializeAll"); }
		$("#supportedthirdPartyLibs").remove();
		$("#thirdPartyLibTree").jstree('destroy');
		$("#thirdPartyLibTree").remove();
		$("#supportedperFunctions").remove();
		$("#perFunctionTree").jstree('destroy');
		$("#perFunctionTree").remove();

		g_groupIds = {};
		g_recordedIds = {};
		g_perControls = {};

		for (i = 0, max = g_field1SubDIVs.length; i < max; i += 1) {
			if (typeof ($("#" + g_field1SubDIVs[i])) !== 'undefined' &&
				$("#" + g_field1SubDIVs[i]).alpaca("exists")) {
				if (!g_bReadyForRelease && window.console) { window.console.log("In initializeAll, remove: " + g_field1SubDIVs[i]); }
				$("#" + g_field1SubDIVs[i]).alpaca("destroy");
				$("#" + g_field1SubDIVs[i]).remove();
			}
		}

		g_lastCheckedSnippetNode = "";

		g_alpacaFormRepository = [];
		g_module_snippet_code = [];
		g_module_snippet_header = [];
		g_module_snippet_pin = [];
		g_module_snippet_clock = [];
		g_module_snippet_peripheral = [];
		g_module_snippet_buttonId = [];

		g_field1SubDIVs = [];
		g_field1SubDIVsCache = {};
		g_alpacaFormIndex = 0;
		g_field1SubIndex = 0;

		$field1.empty();
		$("#canvas_Peripheral").hide();
		$("#GenerateCode_pre").empty();
		$("#GenerateCode_pre").hide();
		$('.prettyprinted').removeClass('prettyprinted');
		$("#field1_canvas").remove();
		$("#field1_anchor").remove();

		removeAlldialogs();
		$.toast().reset('all');
	}

	function refresh() {
		buildThirdPartyLibTree();
		buildMCUselect();
		buildPerFunctionTree();
		buildControlContainer();
	}

	function showWarningForFieldsInvalid(nodeName, okFunction) {
		var title,
			content,
			okButton,
			cancelButton;

		decideUIlanguage();
		if (g_userSelectUIlanguage.indexOf("Simplified") !== -1) {
			title = '警告';
			content = nodeName + "的某些栏位是无效的。若您仍想要继续该操作，请按'恢复默认设置'并再试一次。但所有栏位将会回复到初始值。若您想要修正它，请按'修正'。";
			okButton = '恢复默认设置';
			cancelButton = '修正';
		}
		else if (g_userSelectUIlanguage.indexOf("Traditional") !== -1) {
			title = '警告';
			content = nodeName + "的某些欄位是無效的。若您仍想要繼續該操作，請按'恢復默認設置'並再試一次。但所有欄位將會回復到初始值。若您想要修正它，請按'修正'。";
			okButton = '恢復默認設置';
			cancelButton = '修正';
		}
		else {
			title = 'Warning';
			content = "Some fields of " + nodeName + " are invalid. If you still want to contiune the operation, please press 'Restore Defaults' and try again. But all the fields will be restored to the default. If you want to fix it, please press 'Fix'.";
			okButton = 'Restore Defaults';
			cancelButton = 'Fix';
		}

		// close the last dialog
		removeAlldialogs();
		// JQuery sets the autofocus on the first input that is found. So play it sneaky by creating a "fake" input at the last line of your dialog
		$('<div id="warningForUncheckNodeDialog"><p>' + content + '</p><input type="text" size="1" style="position:relative;top:-5000px;"/></div>')
			.dialog({
				modal: false,
				draggable: true,
				resizable: false,
				title: title,
				width: 500,
				height: 'auto',
				show: 'fade',
				hide: 'fade',
				buttons: [
					{
						text: okButton,
						click: function () {
							okFunction();
							if ($(this).is(':visible')) {
								$(this).dialog("destroy");
							}
						}
					},
					{
						text: cancelButton,
						click: function () {
							if ($(this).is(':visible')) {
								$(this).dialog("destroy");
							}
						}
					}
				],
			});
	}

	function decideUIlanguage() {
		// [Workaround] - Start
		var recordedUIlanguage = localStorage.getItem("UIlanguage");

        if (typeof (recordedUIlanguage) == 'undefined' || recordedUIlanguage == null) {
            g_userSelectUIlanguage = "English";
        } else {
            g_userSelectUIlanguage = recordedUIlanguage;
        }
        recordedUIlanguage = null;
		// [Workaround] - End
	}

	function generateCodeFunctionByJS(snippetName, mode) {
		var i,
			j,
			max,
			maxJ,
			val,
			precedingPath = "",
			readSnippetFilePath,
			newReadSnippetFile,
			newUpdatedSnippetCode,
			newControlConfig,
			tempString,
			tempString1,
			whileCount = 0,
			whileCount1 = 0,
			tagIds = [],
			localId,
			localIdArray = [],
			localIdArray1 = [],
			localControl = {},
			newControlName = g_partNumber_package.slicePriorToX('('),
			newControlType = g_partNumber_type,
			newControlFilter = {},
			newControlFilterExp,
			localValue,
			localHeader = "",
			localPin = null,
			localClock = null,
			localPeripheral = null,
			localFilter = null,
			localObject = null,
			lcoalDebug = false,
			ar = [],
			sp = [],
			sub = [],
			firstObject = {},
			filterExp;

		function determineSingleDependencyValid(id, dependenciesId) {
			var m,
				n,
				maxM,
				localArray,
				localArray1,
				localObject1 = null,
				ar1 = [],
				sp1 = [],
				sub1 = [],
				first1,
				second1,
				firstObject1 = {},
				filterExp1,
				valid = false;

			if (typeof localControl[id].dependenciesOption === 'undefined' ||
				localControl[id].dependenciesOption === 'none' ||
				localControl[id].dependenciesOption === '') {
				return valid;
			}

			firstObject1 = {};
			if (typeof localControl[id].dependenciesOption == 'object' &&
				typeof localControl[id].dependenciesOption[dependenciesId] !== 'undefined') {
				localObject1 = localControl[id].dependenciesOption;
				if (Array.isArray(localObject1[dependenciesId])) {
					if (localControl[dependenciesId].type === 'select' ||
						localControl[dependenciesId].type === 'integer' ||
						localControl[dependenciesId].type === 'hextext') {
						for (m = 0, maxM = localObject1[dependenciesId].length; m < maxM; m += 1) {
							if (localObject1[dependenciesId][m].toString() === localControl[dependenciesId].data) {
								valid = true;
								if (lcoalDebug) { alert('determineSingleDependencyValid: select/integer/hextext array'); }
								break;
							}
						}
					}
					else {
						localArray1 = localControl[dependenciesId].data.toString().replace(/\[/g, "").replace(/\]/g, "").replace(/\s/g, '').split(',');
						if (localObject1[dependenciesId].equals(localArray1)) {
							valid = true;
							if (lcoalDebug) { alert('determineSingleDependencyValid: object array'); }
						}
					}
				}
				else if (localObject1[dependenciesId].toString().indexOf('|') !== -1 ||
					localObject1[dependenciesId].toString().indexOf('&') !== -1 ||
					localObject1[dependenciesId].toString().indexOf('!') !== -1) {
					first1 = localObject1[dependenciesId];
					second1 = localControl[dependenciesId].data;
					sp1 = first1.split('|');
					ar1 = [];
					for (m = 0; m < sp1.length; m++) {
						sub1 = sp1[m].split('&');
						for (n = 0; n < sub1.length; n++) {
							ar1.push(sub1[n].replace(/\(/g, '').replace(/\)/g, '').replace(/\!/g, '').replace(/\s/g, ''));
						}
					}
					for (m = 0; m < ar1.length; m++) {
						firstObject1[ar1[m]] = 0;
						sp1 = second1.replace(/\[/g, "").replace(/\]/g, "").replace(/\s/g, '').split(',');
						for (n = 0; n < sp1.length; n++) {
							if (sp1[n].toString().trim() === ar1[m].toString().trim()) {
								firstObject1[ar1[m]] = 1;
								break;
							}
						}
					}
					if (!$.isEmptyObject(firstObject1)) {
						first1 = first1.replace(/\|/g, ' or ');
						first1 = first1.replace(/\&/g, ' and ');
						first1 = first1.replace(/\!/g, 'not ');
						try { filterExp1 = compileExpression(first1); } catch (err) {
							if (!g_bReadyForRelease) { alert(id + ' failed at compileExpression. Something was wrong in filterExp.'); }
						}
						if (filterExp1(firstObject1)) {
							valid = true;
							if (lcoalDebug) { alert('determineSingleDependencyValid(' + dependenciesId + '): &|!'); }
						}
					}
				}
				else if (localObject1[dependenciesId].toString().indexOf('>') !== -1 ||
					localObject1[dependenciesId].toString().indexOf('<') !== -1 ||
					localObject1[dependenciesId].toString().indexOf('=') !== -1) {
					first1 = localObject1[dependenciesId];
					second1 = localControl[dependenciesId].data;
					firstObject1.myInteger = second1;
					first1 = "myInteger" + first1;
					try { filterExp1 = compileExpression(first1); } catch (err) {
						if (!g_bReadyForRelease) { alert(id + ' failed at compileExpression. Something was wrong in filterExp.'); }
					}
					if (filterExp1(firstObject1)) {
						valid = true;
						if (lcoalDebug) { alert('determineSingleDependencyValid(' + dependenciesId + '): >=<'); }
					}
				}
				else if (localObject1[dependenciesId].toString() === localControl[dependenciesId].data) {
					valid = true;
					if (lcoalDebug) { alert('determineSingleDependencyValid(' + dependenciesId + '): object single'); }
				}
			}
			else if (Array.isArray(localControl[id].dependenciesOption)) {
				if (localControl[dependenciesId].type === 'select' ||
					localControl[dependenciesId].type === 'integer' ||
					localControl[dependenciesId].type === 'hextext') {
					for (m = 0, maxM = localControl[id].dependenciesOption.length; m < maxM; m += 1) {
						if (localControl[id].dependenciesOption[m].toString() === localControl[dependenciesId].data) {
							valid = true;
							if (lcoalDebug) { alert('determineSingleDependencyValid: select/integer/hextext array'); }
							break;
						}
					}
				}
				else {
					localArray1 = localControl[dependenciesId].data.toString().replace(/\[/g, "").replace(/\]/g, "").replace(/\s/g, '').split(',');
					if (localControl[id].dependenciesOption.equals(localArray1)) {
						valid = true;
						if (lcoalDebug) { alert('determineSingleDependencyValid: array'); }
					}
				}
			}
			else if (localControl[id].dependenciesOption.indexOf('[') !== -1 &&
				localControl[dependenciesId].data.indexOf('[') !== -1) {
				localArray = localControl[id].dependenciesOption.replace(/\[/g, "").replace(/\]/g, "").replace(/\s/g, '').split(',');
				localArray1 = localControl[dependenciesId].data.toString().replace(/\[/g, "").replace(/\]/g, "").replace(/\s/g, '').split(',');
				if (localControl[dependenciesId].type === 'select' ||
					localControl[dependenciesId].type === 'integer' ||
					localControl[dependenciesId].type === 'hextext') {
					for (m = 0, maxM = localArray.length; m < maxM; m += 1) {
						if (localArray[m].toString() === localControl[dependenciesId].data) {
							valid = true;
							if (lcoalDebug) { alert('determineSingleDependencyValid: select/integer/hextext array'); }
							break;
						}
					}
				}
				else {
					if (localArray.equals(localArray1)) {
						valid = true;
						if (lcoalDebug) { alert('determineSingleDependencyValid: array'); }
					}
				}
			}
			else if (localControl[id].dependenciesOption.toString().indexOf('|') !== -1 ||
				localControl[id].dependenciesOption.toString().indexOf('&') !== -1 ||
				localControl[id].dependenciesOption.toString().indexOf('!') !== -1) {
				first1 = localControl[id].dependenciesOption;
				second1 = localControl[dependenciesId].data;
				sp1 = first1.split('|');
				ar1 = [];
				for (m = 0; m < sp1.length; m++) {
					sub1 = sp1[m].split('&');
					for (n = 0; n < sub1.length; n++) {
						ar1.push(sub1[n].replace(/\(/g, '').replace(/\)/g, '').replace(/\!/g, '').replace(/\s/g, ''));
					}
				}
				for (m = 0; m < ar1.length; m++) {
					firstObject1[ar1[m]] = 0;
					sp1 = second1.replace(/\[/g, "").replace(/\]/g, "").replace(/\s/g, '').split(',');
					for (n = 0; n < sp1.length; n++) {
						if (sp1[n].toString().trim() === ar1[m].toString().trim()) {
							firstObject1[ar1[m]] = 1;
							break;
						}
					}
				}
				if (!$.isEmptyObject(firstObject1)) {
					first1 = first1.replace(/\|/g, ' or ');
					first1 = first1.replace(/\&/g, ' and ');
					first1 = first1.replace(/\!/g, 'not ');
					try { filterExp1 = compileExpression(first1); } catch (err) {
						if (!g_bReadyForRelease) { alert(id + ' failed at compileExpression. Something was wrong in filterExp.'); }
					}
					if (filterExp1(firstObject1)) {
						valid = true;
						if (lcoalDebug) { alert('determineSingleDependencyValid: &|!'); }
					}
				}
			}
			else if (localControl[id].dependenciesOption.toString().indexOf('>') !== -1 ||
				localControl[id].dependenciesOption.toString().indexOf('<') !== -1 ||
				localControl[id].dependenciesOption.toString().indexOf('=') !== -1) {
				first1 = localControl[id].dependenciesOption;
				second1 = localControl[dependenciesId].data;
				firstObject1.myInteger = second1;
				first1 = "myInteger" + first1;
				try { filterExp1 = compileExpression(first1); } catch (err) {
					if (!g_bReadyForRelease) { alert(id + ' failed at compileExpression. Something was wrong in filterExp.'); }
				}
				if (filterExp1(firstObject1)) {
					valid = true;
					if (lcoalDebug) { alert('determineSingleDependencyValid: >=<'); }
				}
			}
			else if (localControl[id].dependenciesOption.toString() === localControl[dependenciesId].data) {
				valid = true;
				if (lcoalDebug) { alert('determineSingleDependencyValid: common'); }
			}

			return valid;
		}

		function handleDependencies(id, level) {
			var j,
				k,
				maxJ,
				id1,
				localDependenciesArray = [];

			if (level > 10) {
				if (!g_bReadyForRelease) { alert("something wrong in handleDependencies"); }
			}
			if (tagIds.indexOf(id) !== -1) {
				// already exist
				return;
			}

			if (typeof localControl[id].dependencies !== 'undefined' &&
				localControl[id].dependencies !== 'none' &&
				localControl[id].dependencies !== '') {
				if (Array.isArray(localControl[id].dependencies)) {
					localDependenciesArray = localControl[id].dependencies;
				}
				else if (localControl[id].dependencies.toString().indexOf('|') !== -1 ||
					localControl[id].dependencies.toString().indexOf('&') !== -1 ||
					localControl[id].dependencies.toString().indexOf('!') !== -1) {
					sp = localControl[id].dependencies.split('|');
					ar = [];
					for (j = 0; j < sp.length; j++) {
						sub = sp[j].split('&');
						for (k = 0; k < sub.length; k++) {
							localDependenciesArray.push(sub[k].replace(/\(/g, '').replace(/\)/g, '').replace(/\!/g, '').replace(/\s/g, ''));
						}
					}
				}
				else {
					localDependenciesArray[0] = localControl[id].dependencies;
				}
				for (j = 0, maxJ = localDependenciesArray.length; j < maxJ; j += 1) {
					if (localIdArray.indexOf(localDependenciesArray[j]) === -1) {
						// id does not exist
						return;
					}
					// handle the chain of dependencies
					if (tagIds.indexOf(localDependenciesArray[j]) === -1) {
						if (localIdArray.indexOf(localDependenciesArray[j]) < localIdArray.indexOf(id)) {
							if (lcoalDebug) { alert('dependencies bypass:' + id + '/Its dependencies:' + localDependenciesArray[j]); }
							return;
						}
						else {
							// recursively handle dependencies
							if (lcoalDebug) { alert('recursively handle dependencies:' + id + '/Its dependencies:' + localDependenciesArray[j]); }
							handleDependencies(localDependenciesArray[j], level + 1);
						}
					}

					if (tagIds.indexOf(localDependenciesArray[j]) === -1) {
						if (lcoalDebug) { alert('dependencies fail:' + id + '/Its dependencies:' + localDependenciesArray[j]); }
						return;
					}
				}

				if (Array.isArray(localControl[id].dependencies)) {
					localValue = true;
					for (j = 0, maxJ = localControl[id].dependencies.length; j < maxJ; j += 1) {
						id1 = localControl[id].dependencies[j];
						if (!determineSingleDependencyValid(id, id1)) {
							localValue = false;
							break;
						}
					}
					if (localValue) {
						if (lcoalDebug) { alert('dependencies array:' + id); }
						tagIds.push(id);
					}
				}
				else if (localControl[id].dependencies.toString().indexOf('|') !== -1 ||
					localControl[id].dependencies.toString().indexOf('&') !== -1 ||
					localControl[id].dependencies.toString().indexOf('!') !== -1) {
					sp = localControl[id].dependencies.split('|');
					ar = [];
					for (j = 0; j < sp.length; j++) {
						sub = sp[j].split('&');
						for (k = 0; k < sub.length; k++) {
							ar.push(sub[k].replace(/\(/g, '').replace(/\)/g, '').replace(/\!/g, '').replace(/\s/g, ''));
						}
					}
					firstObject = {};
					for (j = 0; j < ar.length; j++) {
						if (determineSingleDependencyValid(id, ar[j])) {
							firstObject[ar[j]] = 1;
						}
						else {
							firstObject[ar[j]] = 0;
						}
					}
					tempString = localControl[id].dependencies;
					tempString = tempString.replace(/\|/g, ' or ');
					tempString = tempString.replace(/\&/g, ' and ');
					tempString = tempString.replace(/\!/g, 'not ');

					if (!$.isEmptyObject(firstObject)) {
						try { filterExp = compileExpression(tempString); } catch (err) {
							if (!g_bReadyForRelease) { alert(id + ' failed at compileExpression. Something was wrong in filterExp.'); }
						}
						if (filterExp(firstObject)) {
							if (lcoalDebug) { alert('dependencies &|!:' + id); }
							tagIds.push(id);
						}
					}
				}
				else {
					id1 = localControl[id].dependencies;
					if (typeof localControl[id1] !== 'undefined' &&
						typeof localControl[id1].data !== 'undefined' &&
						determineSingleDependencyValid(id, id1)) {
						if (lcoalDebug) { alert('dependencies single:' + id); }
						tagIds.push(id);
					}
				}
			}
			else { // localControl[id].dependencies is nonexistent
				tagIds.push(id);
			}
		}
		// function entry
		if (typeof mode === 'undefined') {
			mode = 'parseAll';
		}

		if (typeof NUTOOL_PIN !== 'undefined') {
			precedingPath = 'PeripheralConfigure//';
		}

		readSnippetFilePath = precedingPath + g_chipType + '//' + snippetName + '.txt';
		// read the saved config file
		try {
			newUpdatedSnippetCode = newReadSnippetFile = $.ajax({ url: readSnippetFilePath, async: false }).responseText.replace(/\r/g, "");
		}
		catch (err) { return; }
		newReadSnippetFile = newReadSnippetFile.replace(/\/\*[\s\S]*?\*\/|\/\/.*/g, '');
		while (newReadSnippetFile.indexOf('<!') !== -1) {
			newControlConfig = newReadSnippetFile.sliceBetweenXandX('<!', '!>').replace(/\r?\n|\r/g, '');
			whileCount1 = 0;
			while (newControlConfig.indexOf(';') !== -1) {
				tempString = newControlConfig.slicePriorToX(';');
				tempString1 = "";
				tempString1 = tempString.sliceAfterX(':').trim();
				tempString = tempString.slicePriorToX(':').replace(/\s/g, '');

				if (tempString === "id") {
					localId = tempString1;
					localIdArray.push(localId);
					localControl[localId] = {};
				}
				if (tempString === "type") {
					localControl[localId].type = tempString1;
				}
				if (tempString === "data") {
					localControl[localId].data = tempString1;
				}
				if (tempString === "default") {
					localControl[localId].default = tempString1;
				}
				if (tempString === "dependencies") {
					if (tempString1.indexOf('[') === -1) {
						localControl[localId].dependencies = tempString1.trim();
					}
					else {
						localControl[localId].dependencies = tempString1.replace(/\[/g, "").replace(/\]/g, "").replace(/\s/g, '').split(',');
					}
				}
				if (tempString === "dependenciesOption") {
					if (tempString1.indexOf('{') !== -1 && tempString1.indexOf('}') !== -1) {
						localControl[localId].dependenciesOption = JSON.parse(tempString1.replace(/'/g, '"').trim());
					}
					else {
						localControl[localId].dependenciesOption = tempString1.trim();
					}
				}
				if (tempString === "dependenciesDefault") {
					localControl[localId].dependenciesDefault = tempString1.trim();
				}
				if (tempString === "filterExp") {
					localControl[localId].filterExp = tempString1.trim();
				}
				if (tempString === "header") {
					localHeader = tempString1.replace(/\//g, "\\");
				}
				if (tempString === "pin") {
					localPin = JSON.parse(tempString1.replace(/'/g, '"').trim());
					if (typeof localPin[g_partNumber_type] !== 'undefined') {
						localPin = localPin[g_partNumber_type];
					}
					if (typeof localPin[g_partNumber_package.slicePriorToX('(')] !== 'undefined') {
						localPin = localPin[g_partNumber_package.slicePriorToX('(')];
					}
				}
				if (tempString === "clock") {
					localClock = JSON.parse(tempString1.replace(/'/g, '"').trim());
					if (typeof localClock[g_partNumber_type] !== 'undefined') {
						localClock = localClock[g_partNumber_type];
					}
					if (typeof localClock[g_partNumber_package.slicePriorToX('(')] !== 'undefined') {
						localClock = localClock[g_partNumber_package.slicePriorToX('(')];
					}
				}
				if (tempString === "peripheral") {
					localPeripheral = JSON.parse(tempString1.replace(/'/g, '"').trim());
					if (typeof localPeripheral[g_partNumber_type] !== 'undefined') {
						localPeripheral = localPeripheral[g_partNumber_type];
					}
					if (typeof localPeripheral[g_partNumber_package.slicePriorToX('(')] !== 'undefined') {
						localPeripheral = localPeripheral[g_partNumber_package.slicePriorToX('(')];
					}
				}
				if (tempString === "filter") {
					localFilter = JSON.parse(tempString1.replace(/'/g, '"').trim());
				}

				newControlConfig = newControlConfig.sliceAfterX(';');
				if (whileCount1 > 2000) {
					break;
				}
				else {
					whileCount1 = whileCount1 + 1;
				}
			}

			newReadSnippetFile = newReadSnippetFile.sliceAfterX('>');
			if (whileCount > 2000) {
				break;
			}
			else {
				whileCount = whileCount + 1;
			}
		}

		if (mode === 'parseAll') {
			// filter out tags
			if (localFilter !== null) {
				newControlFilter = localFilter;
			}
			if (typeof newControlFilter[newControlName] !== 'undefined') {
				if (typeof newControlFilter[newControlName] == "function") {
					newControlFilter = newControlFilter[newControlName]();
				}
				else {
					newControlFilter = newControlFilter[newControlName];
				}
			}
			else if (typeof newControlFilter[newControlType] !== 'undefined') {
				if (typeof newControlFilter[newControlType] == "function") {
					newControlFilter = newControlFilter[newControlType]();
				}
				else {
					newControlFilter = newControlFilter[newControlType];
				}
			}
			newControlFilter.name = newControlName;
			if (newControlType !== "") {
				newControlFilter.type = newControlType;
			}
			for (val in g_supportedGPIOPins) {
				if (g_supportedGPIOPins.hasOwnProperty(val)) {
					newControlFilter[val] = g_supportedGPIOPins[val];
				}
			}
			for (i = 0, max = localIdArray.length; i < max; i += 1) {
				localId = localIdArray[i];
				if (typeof localControl[localId].filterExp !== 'undefined' &&
					localControl[localId].filterExp !== 'none' &&
					localControl[localId].filterExp !== '') {
					try { newControlFilterExp = compileExpression(localControl[localId].filterExp); } catch (err) {
						if (!g_bReadyForRelease) { alert(localId + ' failed at compileExpression. Something was wrong in filterExp.'); }
					}
					if (newControlFilterExp(newControlFilter)) {
						localIdArray1.push(localId);
					}
				}
				else {
					localIdArray1.push(localId);
				}
			}
			localIdArray = localIdArray1;
			// handle dependencies literally
			for (i = 0, max = localIdArray.length; i < max; i += 1) {
				localId = localIdArray[i];
				handleDependencies(localId, 0);
			}
			if (tagIds.length > 0) {
				// handle the requirement for pin and clock
				if (localPin !== null) {
					delete g_module_snippet_pin[snippetName];
					for (i = 0, max = tagIds.length; i < max; i += 1) {
						localId = tagIds[i];
						if (typeof localPin[localId] !== 'undefined' &&
							typeof localPin[localId][localControl[localId].data] !== 'undefined') {
							if (typeof g_module_snippet_pin[snippetName] === 'undefined') {
								g_module_snippet_pin[snippetName] = [];
							}
							localObject = localPin[localId][localControl[localId].data];
							if (!Array.isArray(localObject)) {
								if ($.inArray(localObject, g_module_snippet_pin[snippetName]) === -1) {
									g_module_snippet_pin[snippetName].push(localObject);
								}
							}
							else {
								for (j = 0, maxJ = localObject.length; j < maxJ; j += 1) {
									if ($.inArray(localObject[j], g_module_snippet_pin[snippetName]) === -1) {
										g_module_snippet_pin[snippetName].push(localObject[j]);
									}
								}
							}
						}
					}
					if (typeof localPin.ALL !== 'undefined') {
						if (typeof g_module_snippet_pin[snippetName] === 'undefined') {
							g_module_snippet_pin[snippetName] = [];
						}
						if (!Array.isArray(localPin.ALL)) {
							if ($.inArray(localPin.ALL, g_module_snippet_pin[snippetName]) === -1) {
								g_module_snippet_pin[snippetName].push(localPin.ALL);
							}
						}
						else {
							for (j = 0, maxJ = localPin.ALL.length; j < maxJ; j += 1) {
								if ($.inArray(localPin.ALL[j], g_module_snippet_pin[snippetName]) === -1) {
									g_module_snippet_pin[snippetName].push(localPin.ALL[j]);
								}
							}
						}
					}
				}
				if (localClock !== null) {
					delete g_module_snippet_clock[snippetName];
					for (i = 0, max = tagIds.length; i < max; i += 1) {
						localId = tagIds[i];
						if (typeof localClock[localId] !== 'undefined' &&
							typeof localClock[localId][localControl[localId].data] !== 'undefined') {
							if (typeof g_module_snippet_clock[snippetName] === 'undefined') {
								g_module_snippet_clock[snippetName] = [];
							}
							localObject = localClock[localId][localControl[localId].data];
							if (!Array.isArray(localObject)) {
								if ($.inArray(localObject, g_module_snippet_clock[snippetName]) === -1) {
									g_module_snippet_clock[snippetName].push(localObject);
								}
							}
							else {
								for (j = 0, maxJ = localObject.length; j < maxJ; j += 1) {
									if ($.inArray(localObject[j], g_module_snippet_clock[snippetName]) === -1) {
										g_module_snippet_clock[snippetName].push(localObject[j]);
									}
								}
							}
						}
					}
					if (typeof localClock.ALL !== 'undefined') {
						if (typeof g_module_snippet_clock[snippetName] === 'undefined') {
							g_module_snippet_clock[snippetName] = [];
						}
						if (!Array.isArray(localClock.ALL)) {
							if ($.inArray(localClock.ALL, g_module_snippet_clock[snippetName]) === -1) {
								g_module_snippet_clock[snippetName].push(localClock.ALL);
							}
						}
						else {
							for (j = 0, maxJ = localClock.ALL.length; j < maxJ; j += 1) {
								if ($.inArray(localClock.ALL[j], g_module_snippet_clock[snippetName]) === -1) {
									g_module_snippet_clock[snippetName].push(localClock.ALL[j]);
								}
							}
						}
					}
				}
				if (localPeripheral !== null) {
					delete g_module_snippet_peripheral[snippetName];
					for (i = 0, max = tagIds.length; i < max; i += 1) {
						localId = tagIds[i];
						if (typeof localPeripheral[localId] !== 'undefined' &&
							typeof localPeripheral[localId][localControl[localId].data] !== 'undefined') {
							if (typeof g_module_snippet_peripheral[snippetName] === 'undefined') {
								g_module_snippet_peripheral[snippetName] = [];
							}
							localObject = localPeripheral[localId][localControl[localId].data];
							if (!Array.isArray(localObject)) {
								if ($.inArray(localObject, g_module_snippet_peripheral[snippetName]) === -1) {
									g_module_snippet_peripheral[snippetName].push(localObject);
								}
							}
							else {
								for (j = 0, maxJ = localObject.length; j < maxJ; j += 1) {
									if ($.inArray(localObject[j], g_module_snippet_peripheral[snippetName]) === -1) {
										g_module_snippet_peripheral[snippetName].push(localObject[j]);
									}
								}
							}
						}
					}
					if (typeof localPeripheral.ALL !== 'undefined') {
						if (typeof g_module_snippet_peripheral[snippetName] === 'undefined') {
							g_module_snippet_peripheral[snippetName] = [];
						}
						if (!Array.isArray(localPeripheral.ALL)) {
							if ($.inArray(localPeripheral.ALL, g_module_snippet_peripheral[snippetName]) === -1) {
								g_module_snippet_peripheral[snippetName].push(localPeripheral.ALL);
							}
						}
						else {
							for (j = 0, maxJ = localPeripheral.ALL.length; j < maxJ; j += 1) {
								if ($.inArray(localPeripheral.ALL[j], g_module_snippet_peripheral[snippetName]) === -1) {
									g_module_snippet_peripheral[snippetName].push(localPeripheral.ALL[j]);
								}
							}
						}
					}
				}
				for (i = 0, max = tagIds.length; i < max; i += 1) {
					localId = tagIds[i];
					if (typeof localControl[localId].data !== 'undefined') {
						if (localId.toString().toLowerCase().indexOf('textonly') === -1) {
							localValue = localControl[localId].data.toString().replace(/\[/g, "").replace(/\]/g, "").replace(/,/g, "|").trim();
						}
						else {
							localValue = "NUC_NULL";
						}
						newUpdatedSnippetCode = replaceTag(newUpdatedSnippetCode, localId, localValue, 'entireTag');
					}
				}
				for (i = 0, max = localIdArray.length; i < max; i += 1) {
					localId = localIdArray[i];
					if ($.inArray(localId, tagIds) === -1 &&
						(localControl[localId].type === 'multipleselect' || localControl[localId].type === 'checkbox')) {
						localValue = '0';
						newUpdatedSnippetCode = replaceTag(newUpdatedSnippetCode, localId, localValue, 'entireTag');
					}
					if ($.inArray(localId, tagIds) === -1) {
						if (typeof localControl[localId].default !== 'undefined') {
							localValue = localControl[localId].default.toString().replace(/\[/g, "").replace(/\]/g, "").replace(/,/g, "|").trim();
						}
						else {
							localValue = 'NUC_NULL';
						}
						if (typeof localControl[localId].dependenciesDefault !== 'undefined' &&
							localControl[localId].dependenciesDefault !== 'true') {
							localValue = 'NUC_NULL';
						}
						newUpdatedSnippetCode = replaceTag(newUpdatedSnippetCode, localId, localValue, 'entireTag');
					}
				}
			}
			newUpdatedSnippetCode = removeAllTags(newUpdatedSnippetCode);
			g_module_snippet_code[snippetName] = newUpdatedSnippetCode;
			if (lcoalDebug) { alert(newUpdatedSnippetCode); }
			newUpdatedSnippetCode = "";
		}
		// Parsing Header
		if (localHeader !== "") {
			if (localHeader.indexOf(".h") !== -1) {
				g_module_snippet_header[snippetName] = localHeader;
			}
			else {
				g_module_snippet_header[snippetName] = localHeader + ".h";
			}
		}
		else {
			g_module_snippet_header[snippetName] = "periph_conf.h";
		}
	}

	function openFromChipSelection() {
		var query, bResult = false;
		query = window.location.search;
		// Skip the leading ?, which should always be there,
		// but be careful anyway
		if (query.substring(0, 1) == '?') {
			query = query.substring(1);
		}
		if (query !== "") {
			g_selectedPartNoValue = query;
			NUTOOL_PIN.setg_selectedPartNoValue(g_selectedPartNoValue);
			NUTOOL_CLOCK.setg_selectedPartNoValue(g_selectedPartNoValue);

			NUTOOL_PIN.loadPinConfigureTool_fromSelectionGuide();
			NUTOOL_CLOCK.loadClockConfigureTool_fromSelectionGuide();
			afterMCUchange();

			bResult = true;
		}

		return bResult;
	}

	function showModulesNeedChecking() {
		var i,
			max,
			currentState = "",
			currentStateArray = [],
			currentMFPList = "",
			snippetName,
			snippetArray = [],
			toastHeading = "",
			warningArray = [],
			recordedUIlanguage = localStorage.getItem("UIlanguage");

		if (typeof (recordedUIlanguage) !== 'undefined' || recordedUIlanguage == null) {
			if (recordedUIlanguage === "Simplified Chinese") {
				toastHeading = "需检查的模块于";
			}
			else if (recordedUIlanguage === "Traditional Chinese") {
				toastHeading = "需檢查的模組於";
			}
			else {
				toastHeading = "Modules need checking in ";
			}
		}
		else {
			toastHeading = "Modules need checking in ";
		}

		if (typeof NUTOOL_PIN !== 'undefined') {
			$.toast().reset('all');
			NUTOOL_PIN.getGeneratedCodeByPin('primitiveDescription');
			NUTOOL_PIN.getGeneratedMFPFunctionList();
			currentState = NUTOOL_PIN.getg_generatedCodeByPinString();
			currentMFPList = NUTOOL_PIN.getg_generatedMFPFunctionList();
			warningArray = [];
			for (snippetName in g_module_snippet_pin) {
				if (g_module_snippet_pin.hasOwnProperty(snippetName) &&
					typeof g_module_snippet_pin[snippetName] !== 'undefined') {
					for (i = 0, max = g_module_snippet_pin[snippetName].length; i < max; i++) {
						if (currentState.indexOf(":" + g_module_snippet_pin[snippetName][i] + "\n") === -1 &&
							currentMFPList.indexOf("/" + g_module_snippet_pin[snippetName][i] + ":") !== -1 &&
							$.inArray(g_module_snippet_pin[snippetName][i], warningArray) === -1) {
							warningArray.push(g_module_snippet_pin[snippetName][i]);
						}
					}
				}
			}
			if (warningArray.length > 0) {
				warningArray.sort(natualSort);
				currentState = '';
				for (i = 0, max = warningArray.length; i < max; i++) {
					currentState += warningArray[i];
					if (i !== max - 1) {
						currentState += ', ';
					}
				}
				currentState += '<br />';
				g_toast_pin = $.toast({
					heading: toastHeading + 'PinConfigure:',
					text: currentState,
					icon: 'warning',
					position: 'bottom-right',
					hideAfter: false,
					onClick: function () { showPinConfigure(); }
				});
			}

			NUTOOL_CLOCK.getGeneratedClockStatus();
			currentState = NUTOOL_CLOCK.getg_clockRegsString();
			warningArray = [];
			for (snippetName in g_module_snippet_clock) {
				if (g_module_snippet_clock.hasOwnProperty(snippetName) &&
					typeof g_module_snippet_clock[snippetName] !== 'undefined') {
					for (i = 0, max = g_module_snippet_clock[snippetName].length; i < max; i++) {
						if (currentState.indexOf(":" + g_module_snippet_clock[snippetName][i] + "=Enabled") === -1 &&
							currentState.indexOf(":" + g_module_snippet_clock[snippetName][i] + "/") !== -1 &&
							$.inArray(g_module_snippet_clock[snippetName][i], warningArray) === -1) {
							warningArray.push(g_module_snippet_clock[snippetName][i]);
						}
					}
				}
			}
			if (warningArray.length > 0) {
				warningArray.sort(natualSort);
				currentState = '';
				for (i = 0, max = warningArray.length; i < max; i++) {
					currentState += warningArray[i];
					if (i !== max - 1) {
						currentState += ', ';
					}
				}
				currentState += '<br />';
				g_toast_clock = $.toast({
					heading: toastHeading + 'ClockConfigure:',
					text: currentState,
					icon: 'warning',
					position: 'bottom-right',
					hideAfter: false,
					onClick: function () { showClockConfigure(); }
				});
			}

			snippetArray = [];
			for (snippetName in g_module_snippet) {
				if (g_module_snippet.hasOwnProperty(snippetName)) {
					if (g_module_snippet[snippetName].length > 1) {
						snippetArray.push(g_module_snippet[snippetName]);
					}
					else {
						snippetArray.push(snippetName);
					}
				}
			}
			// [Workaround]
			NUTOOL_PER.concatenate_generated_cfg();
			currentStateArray = g_enabledPeripheralFunctionString.split('/');
			warningArray = [];
			for (snippetName in g_module_snippet_peripheral) {
				if (g_module_snippet_peripheral.hasOwnProperty(snippetName) &&
					typeof g_module_snippet_peripheral[snippetName] !== 'undefined') {
					for (i = 0, max = g_module_snippet_peripheral[snippetName].length; i < max; i++) {
						if (snippetArray.indexOf(g_module_snippet_peripheral[snippetName][i]) !== -1 &&
							currentStateArray.indexOf(g_module_snippet_peripheral[snippetName][i]) === -1 &&
							$.inArray(g_module_snippet_peripheral[snippetName][i], warningArray) === -1) {
							warningArray.push(g_module_snippet_peripheral[snippetName][i]);
						}
					}
				}
			}
			if (warningArray.length > 0) {
				warningArray.sort(natualSort);
				currentState = '';
				for (i = 0, max = warningArray.length; i < max; i++) {
					currentState += warningArray[i];
					if (i !== max - 1) {
						currentState += ', ';
					}
				}
				currentState += '<br />';
				g_toast_peripheral = $.toast({
					heading: toastHeading + 'PeripheralConfigure:',
					text: currentState,
					icon: 'warning',
					position: 'bottom-right',
					hideAfter: false,
					onClick: function () { showPeripheralConfigure(); }
				});
			}
		}
	}
	///////////////////////////////////// following functions will be invoked by the CDHtmlDialog ///////////////////////////
	function showPinConfigure() {
		replacejscssfile('PeripheralConfigure/bootstrap-multiselect.css', '', 'css');
		replacejscssfile('PeripheralConfigure/bootstrap.min.css', '', 'css');
		replacejscssfile('PinConfigure/NUC_Pin_Configuration.css', 'ClockConfigure/NUC_Clock_Configuration.css', 'css');
		replacejscssfile('ClockConfigure/pepper-grinder/jquery-ui-1.10.4.custom.css', 'PinConfigure/css/pepper-grinder/jquery-ui-1.10.3.custom.css', 'css');

		$('#ChipType_Peripheral').hide();
		$('#MCU_Peripheral').hide();

		$("#CodeGeneratorContainer").hide();
		$('#rootTree_Peripheral').hide();

		$("#parentOfPanel").show();
		$('#rootTree_Pin').show();

		$("#tabs")[0].style.visibility = 'hidden';
		$('#rootTree_Clock').hide();

		showModulesNeedChecking();
		if (typeof g_toast_clock !== 'undefined') {
			g_toast_clock.hide();
		}
		if (typeof g_toast_peripheral !== 'undefined') {
			g_toast_peripheral.hide();
		}

		g_currentTool = "PinConfigure";
		removeAlldialogs();
	}

	function showClockConfigure() {
		replacejscssfile('PeripheralConfigure/bootstrap-multiselect.css', '', 'css');
		replacejscssfile('PeripheralConfigure/bootstrap.min.css', '', 'css');
		replacejscssfile('PinConfigure/NUC_Pin_Configuration.css', 'ClockConfigure/NUC_Clock_Configuration.css', 'css');
		replacejscssfile('PinConfigure/css/pepper-grinder/jquery-ui-1.10.3.custom.css', 'ClockConfigure/pepper-grinder/jquery-ui-1.10.4.custom.css', 'css');

		$('#ChipType_Peripheral').hide();
		$('#MCU_Peripheral').hide();

		$("#CodeGeneratorContainer").hide();
		$('#rootTree_Peripheral').hide();

		$("#parentOfPanel").hide();
		$('#rootTree_Pin').hide();

		$("#tabs")[0].style.visibility = 'visible';
		$('#rootTree_Clock').show();

		showModulesNeedChecking();
		if (typeof g_toast_pin !== 'undefined') {
			g_toast_pin.hide();
		}
		if (typeof g_toast_peripheral !== 'undefined') {
			g_toast_peripheral.hide();
		}

		g_currentTool = "ClockConfigure";
		removeAlldialogs();
	}

	function showPeripheralConfigure() {
		replacejscssfile('PinConfigure/NUC_Pin_Configuration.css', 'PeripheralConfigure/NUC_Peripheral_Configuration.css', 'css');
		replacejscssfile('ClockConfigure/NUC_Clock_Configuration.css', 'PeripheralConfigure/bootstrap-multiselect.css', 'css');
		replacejscssfile('ClockConfigure/NUC_Clock_Configuration.css', 'PeripheralConfigure/bootstrap.min.css', 'css');
		replacejscssfile('ClockConfigure/pepper-grinder/jquery-ui-1.10.4.custom.css', 'PinConfigure/css/pepper-grinder/jquery-ui-1.10.3.custom.css', 'css');

		$('#ChipType_Peripheral').show();
		$('#MCU_Peripheral').show();
		$('#perFunctionTree').show();
		$('#thirdPartyLibTree').show();
		$('#supportedperFunctions').show();
		$('#supportedthirdPartyLibs').show();
		$("#CodeGeneratorContainer").css({ left: g_NUC_TreeView_Width - 16 + 'px' });
		$("#CodeGeneratorContainer").css('width', (g_Dialog_Width - g_NUC_TreeView_Width + 16) + 'px');

		$("#CodeGeneratorContainer").show();
		$('#rootTree_Peripheral').show();

		$("#parentOfPanel").hide();
		$('#rootTree_Pin').hide();

		$("#tabs")[0].style.visibility = 'hidden';
		$('#rootTree_Clock').hide();

		showModulesNeedChecking();
		if (typeof g_toast_pin !== 'undefined') {
			g_toast_pin.show();
		}
		if (typeof g_toast_clock !== 'undefined') {
			g_toast_clock.show();
		}
		if (typeof g_toast_peripheral !== 'undefined') {
			g_toast_peripheral.show();
		}
		if ($("#" + g_lastCheckedSnippetNode).hasClass('jstree-checked') &&
			$("#" + g_module_snippet_buttonId[g_lastCheckedSnippetNode.slicePriorToX('_PeripheralConfigure')]).alpaca("exists")) {
			$("#" + g_module_snippet_buttonId[g_lastCheckedSnippetNode.slicePriorToX('_PeripheralConfigure')]).alpaca("get").form.getButtonEl("submit").click();
		}

		g_currentTool = "PeripheralConfigure";
		removeAlldialogs();
	}

	function showCodeOnly() {
		if ($('#ChipType_Peripheral').css('display') === 'none'/* || $('#field1_canvas').length*/) {
			$('#ChipType_Peripheral').show();
			$('#MCU_Peripheral').show();
			$('#perFunctionTree').show();
			$('#thirdPartyLibTree').show();
			$('#supportedperFunctions').show();
			$('#supportedthirdPartyLibs').show();
			$("#CodeGeneratorContainer").css({ left: g_NUC_TreeView_Width - 16 + 'px' });
			$("#CodeGeneratorContainer").css('width', (g_Dialog_Width - g_NUC_TreeView_Width + 16) + 'px');
		}
		else {
			$('#ChipType_Peripheral').hide();
			$('#MCU_Peripheral').hide();
			$('#perFunctionTree').hide();
			$('#thirdPartyLibTree').hide();
			$('#supportedperFunctions').hide();
			$('#supportedthirdPartyLibs').hide();
			$('#CodeGeneratorContainer').css({ left: '0px' });
			$('#CodeGeneratorContainer').css('width', g_Dialog_Width + 'px');
		}
	}

	function prepare_generated_code() {
		var i,
			max,
			moduleNames,
			snippetReadyModuleNames,
			currentNode,
			childNode,
			userHeaderArray = [];

		function f1(index, listItem) {
			childNode = $(listItem).attr("id").slicePriorToX('_PeripheralConfigure');
			if ($("#" + childNode + '_PeripheralConfigure').hasClass('jstree-checked')) {
				if ($.inArray(childNode, snippetReadyModuleNames) === -1) {
					preprocessTagFile(childNode);
					generateCodeFunctionByJS(childNode);
				}
			}
			else {
				generateCodeFunctionByJS(childNode, 'onlyParsingHeader');
			}
		}

		if ($("#" + g_lastCheckedSnippetNode).hasClass('jstree-checked') &&
			$("#" + g_module_snippet_buttonId[g_lastCheckedSnippetNode.slicePriorToX('_PeripheralConfigure')]).alpaca("exists")) {
			$("#" + g_module_snippet_buttonId[g_lastCheckedSnippetNode.slicePriorToX('_PeripheralConfigure')]).alpaca("get").form.getButtonEl("submit").click();
			// restore UI
			$("#canvas_Peripheral").hide();
			$("#GenerateCode_pre").empty();
			$("#GenerateCode_pre").hide();
			$('.prettyprinted').removeClass('prettyprinted');
		}

		snippetReadyModuleNames = getPropertyNames(g_module_snippet_code);
		moduleNames = getPropertyNames(g_module_snippet);
		moduleNames.sort(natualSort);
		for (i = 0, max = moduleNames.length; i < max; i += 1) {
			currentNode = moduleNames[i];
			if ($("#" + currentNode + '_PeripheralConfigure').find("li").length > 0) {
				$("#" + currentNode + '_PeripheralConfigure').find("li").each(f1);
			}
			else {
				if ($("#" + currentNode + '_PeripheralConfigure').hasClass('jstree-checked')) {
					if ($.inArray(currentNode, snippetReadyModuleNames) === -1) {
						preprocessTagFile(currentNode);
						generateCodeFunctionByJS(currentNode);
					}
				}
				else {
					generateCodeFunctionByJS(currentNode, 'onlyParsingHeader');
				}
			}
		}

		for (i in g_module_snippet_header) {
			if (g_module_snippet_header[i].toString().indexOf('.h') !== -1 &&
				g_module_snippet_header[i].toString().slice(-1) === 'h' &&
				$.inArray(g_module_snippet_header[i], userHeaderArray) === -1) {
				userHeaderArray.push(g_module_snippet_header[i]);
			}
		}
		g_userHeader = "";
		for (i = 0, max = userHeaderArray.length; i < max; i++) {
			g_userHeader += userHeaderArray[i];
			if (i !== max - 1) {
				g_userHeader += '>';
			}
		}
	}

	function concatenate_generated_cfg() {
		var i,
			max,
			moduleNames,
			tempArray = [],
			tempObject = {},
			snippetReadyModuleNames,
			currentNode,
			childNode,
			precedingPath;

		function f2(index, listItem) {
			childNode = $(listItem).attr("id").slicePriorToX('_PeripheralConfigure');
			if ($("#" + childNode + '_PeripheralConfigure').hasClass('jstree-checked')) {
				tempArray.push(childNode);
			}
		}

		g_generatedCodeFromPerString = "";
		moduleNames = NUTOOL_PER.g_cfg_thirdPartyLibs;
		moduleNames.sort(natualSort);
		for (i = 0, max = moduleNames.length; i < max; i += 1) {
			currentNode = moduleNames[i];
			if ($("#" + currentNode.replaceSpecialCharacters() + '_PeripheralConfigure').hasClass('jstree-checked')) {
				tempArray.push(currentNode);
			}
		}

		g_enabledThirdPartyLibString = "";
		for (i = 0, max = tempArray.length; i < max; i += 1) {
			g_enabledThirdPartyLibString += tempArray[i];
			if (i !== max - 1) {
				g_enabledThirdPartyLibString += "/";
			}
		}

		tempArray = [];
		snippetReadyModuleNames = getPropertyNames(g_module_snippet_code);
		moduleNames = getPropertyNames(g_module_snippet);
		moduleNames.sort(natualSort);
		for (i = 0, max = moduleNames.length; i < max; i += 1) {
			currentNode = moduleNames[i];
			if ($("#" + currentNode + '_PeripheralConfigure').find("li").length > 0) {
				$("#" + currentNode + '_PeripheralConfigure').find("li").each(f2);
			}
			else if ($("#" + currentNode + '_PeripheralConfigure').hasClass('jstree-checked')) {
				tempArray.push(currentNode);
			}
		}

		if (typeof NUTOOL_PIN !== 'undefined') {
			precedingPath = 'PeripheralConfigure//';
		}

		g_generatedCodeFromPerString = "";
		g_enabledPeripheralFunctionString = "";
		for (i = 0, max = tempArray.length; i < max; i += 1) {
			g_enabledPeripheralFunctionString += tempArray[i];
			if (i !== max - 1) {
				g_enabledPeripheralFunctionString += "/";
			}
			tempObject[tempArray[i]] = savePerControls(precedingPath + g_chipType + '//' + tempArray[i] + '.txt');
		}
		if (tempArray.length > 0) {
			g_generatedCodeFromPerString = JSON.stringify(tempObject);
		}
	}

	function concatenate_generated_code() {
		var i,
			j,
			max,
			maxJ,
			moduleNames,
			snippetReadyModuleNames,
			currentNode,
			childNode,
			childNodeHasBeenEnabled,
			local_module_snippet_primitive = clone(g_module_snippet_primitive);
		local_module_snippet_code = "";

		function f1(index, listItem) {
			childNode = $(listItem).attr("id").slicePriorToX('_PeripheralConfigure');
			if ($("#" + childNode + '_PeripheralConfigure').hasClass('jstree-checked')) {
				childNodeHasBeenEnabled = true;
			}
		}

		function f2(index, listItem) {
			childNode = $(listItem).attr("id").slicePriorToX('_PeripheralConfigure');
			if (NUTOOL_PER.g_perFunctionString === "periph_conf.h") {
				if ($("#" + childNode + '_PeripheralConfigure').hasClass('jstree-checked')) {
					g_generatedCodeFromPerString += "#define NUCODEGEN_" + childNode + " 1\n";
				}
				else {
					g_generatedCodeFromPerString += "#define NUCODEGEN_" + childNode + " 0\n";
				}

				j = local_module_snippet_primitive[currentNode].indexOf(childNode);
				if (j !== -1) {
					local_module_snippet_primitive[currentNode].splice(j, 1);
				}
			}
			if ((NUTOOL_PER.g_perFunctionString === g_module_snippet_header[childNode] || NUTOOL_PER.g_perFunctionString === "") &&
				$("#" + childNode + '_PeripheralConfigure').hasClass('jstree-checked') &&
				$.inArray(childNode, snippetReadyModuleNames) !== -1) {
				local_module_snippet_code += g_module_snippet_code[childNode] + "\n";
			}
		}

		g_generatedCodeFromPerString = "";
		moduleNames = NUTOOL_PER.g_cfg_thirdPartyLibs;
		moduleNames.sort(natualSort);
		for (i = 0, max = moduleNames.length; i < max; i += 1) {
			currentNode = moduleNames[i];

			if ($("#" + currentNode.replaceSpecialCharacters() + '_PeripheralConfigure').hasClass('jstree-checked')) {
				g_generatedCodeFromPerString += "#define NUCODEGEN_" + currentNode + " 1\n";
			}
			else {
				g_generatedCodeFromPerString += "#define NUCODEGEN_" + currentNode + " 0\n";
			}
		}

		if (NUTOOL_PER.g_perFunctionString === "periph_conf.h") {
			local_module_snippet_code = "// MACROs above generated by the NuCodeGenerator tool\n\n";
		}
		if (NUTOOL_PER.g_bFunctionalTesting) {
			local_module_snippet_code += "#define NUCODEGEN_UTEST 1\n\n";
		}

		snippetReadyModuleNames = getPropertyNames(g_module_snippet_code);
		moduleNames = getPropertyNames(g_module_snippet);
		moduleNames.sort(natualSort);
		for (i = 0, max = moduleNames.length; i < max; i += 1) {
			currentNode = moduleNames[i];
			if ($("#" + currentNode + '_PeripheralConfigure').find("li").length > 0) {
				if (NUTOOL_PER.g_perFunctionString === "periph_conf.h") {
					childNodeHasBeenEnabled = false;
					$("#" + currentNode + '_PeripheralConfigure').find("li").each(f1);
					if (childNodeHasBeenEnabled) {
						g_generatedCodeFromPerString += "#define NUCODEGEN_" + currentNode + " 1\n";
					}
					else {
						g_generatedCodeFromPerString += "#define NUCODEGEN_" + currentNode + " 0\n";
					}
				}

				$("#" + currentNode + '_PeripheralConfigure').find("li").each(f2);
			}
			else {
				if (NUTOOL_PER.g_perFunctionString === "periph_conf.h") {
					if ($("#" + currentNode + '_PeripheralConfigure').hasClass('jstree-checked')) {
						g_generatedCodeFromPerString += "#define NUCODEGEN_" + currentNode + " 1\n";
					}
					else {
						g_generatedCodeFromPerString += "#define NUCODEGEN_" + currentNode + " 0\n";
					}

					j = local_module_snippet_primitive[currentNode].indexOf(currentNode);
					if (j !== -1) {
						local_module_snippet_primitive[currentNode].splice(j, 1);
					}
				}
				if ((NUTOOL_PER.g_perFunctionString === g_module_snippet_header[currentNode] || NUTOOL_PER.g_perFunctionString === "") &&
					$("#" + currentNode + '_PeripheralConfigure').hasClass('jstree-checked') &&
					$.inArray(currentNode, snippetReadyModuleNames) !== -1) {
					local_module_snippet_code += g_module_snippet_code[currentNode] + "\n";
				}
			}
		}

		// for unused perFunctions, their macro should be defined as 0.
		moduleNames = getPropertyNames(local_module_snippet_primitive);
		moduleNames.sort(natualSort);
		for (i = 0, max = moduleNames.length; i < max; i += 1) {
			currentNode = moduleNames[i];
			if (local_module_snippet_primitive[currentNode].length !== 0 &&
				local_module_snippet_primitive[currentNode].length === g_module_snippet_primitive[currentNode].length) {
				g_generatedCodeFromPerString += "#define NUCODEGEN_" + currentNode + " 0\n";
			}
			for (j = 0, maxJ = local_module_snippet_primitive[currentNode].length; j < maxJ; j += 1) {
				if (local_module_snippet_primitive[currentNode][j] !== currentNode) {
					g_generatedCodeFromPerString += "#define NUCODEGEN_" + local_module_snippet_primitive[currentNode][j] + " 0\n";
				}
			}
		}
		g_generatedCodeFromPerString = g_generatedCodeFromPerString + "\n" + local_module_snippet_code;
	}

	function loadConfig() {
		try { external.loadConfigFromJS(); } catch (err) { }
	}

	function loadConfig_core() {
		initializeAll();
		if (!decideChipTypeAndTreeContent()) {
			showAlertDialog("配置档不正确。",
				"配置檔不正確。",
				"The config file is incorrect.");
			g_bCheckNodesBasedOnConfigFile = false;
		}
		refresh();

		if (typeof NUTOOL_PIN !== 'undefined') {
			// determine the caption of the dialog
			try { external.changeDialogCaptionFromJS('NuTool - CodeGenerator_' + NUTOOL_PER.g_toolVersion); } catch (err) { }//+': ' + g_partNumber_package); } catch (err) { }
		}
	}

	function saveConfig() {
		var precedingPath = "";

		// prevent the user from generating wrong code
		if (!g_bAlpacaValidationResult) {
			if (typeof NUTOOL_PIN !== 'undefined') {
				precedingPath = 'PeripheralConfigure//';
			}
			showWarningForFieldsInvalid(
				g_lastCheckedSnippetNode.slicePriorToX('_PeripheralConfigure'),
				function () {
					//$('#' + currentNode + '_PeripheralConfigure').removeClass('jstree-checked jstree-undetermined').addClass('jstree-unchecked');
					restorePerControlsToDefault(precedingPath + g_chipType + '//' + g_lastCheckedSnippetNode.slicePriorToX('_PeripheralConfigure') + '.txt');
					delete g_field1SubDIVsCache[g_lastCheckedSnippetNode.slicePriorToX('_PeripheralConfigure')];
					alpacaValidationSuccess();
					$('#perFunctionTree').jstree("uncheck_node", $('#' + g_lastCheckedSnippetNode));
				});
			return;
		}
		if ($("#" + g_lastCheckedSnippetNode).hasClass('jstree-checked') &&
			$("#" + g_module_snippet_buttonId[g_lastCheckedSnippetNode.slicePriorToX('_PeripheralConfigure')]).alpaca("exists")) {
			$("#" + g_module_snippet_buttonId[g_lastCheckedSnippetNode.slicePriorToX('_PeripheralConfigure')]).alpaca("get").form.getButtonEl("submit").click();
			// restore UI
			$("#canvas_Peripheral").hide();
			$("#GenerateCode_pre").empty();
			$("#GenerateCode_pre").hide();
			$('.prettyprinted').removeClass('prettyprinted');
		}
		try { external.saveConfigFromJS("NUC_BROWSE_PROJECT_PATH"); } catch (err) { }
	}

	function generateCode() {
		var i,
			max,
			title,
			projectName,
			content,
			content2,
			checkBSPCompatibilityChecked = "",
			checkProjfileChecked = "checked=true",
			checkCppcmdChecked = "checked=true",
			checkRenameChecked = "checked=true",
			checkAStyleChecked = "checked=true",
			checkbox_ModularizeCodeChecked = "checked=true",
			checkBSPCompatibilityText,
			checkboxModularize,
			checkboxModularizeType,
			checkboxModularizeNotSupportedList = ['MA35D1', 'ML51', 'ML56', 'ML5156', 'MS51_8K', 'MS51_8KDB', 'MS51_16K', 'MS51_32K'],
			checkboxReviewReport,
			buildReviewReportTable,
			sTitle_Pin_inner = "",
			sTitle_Clock_inner = "",
			sTitle_Description_inner = "",
			sTitle_UserDefined_inner = "",
			sTitle_Module_inner = "",
			sTitle_BusClock_inner = "",
			sTitle_EngineClock_inner = "",
			sTooltip_inner = "",
			sNoData_inner = "",
			reviewReportTable_Pin = null,
			reviewReportTable_Clock = null,
			reviewReportTableHeight,
			tableDataArray_Pin = [],
			tableDataArray_Clock = [],
			downloadBSPFunction,
			downloadBSPManagerText = "",
			downloadBSPManagerSelect = "",
			downloadBSPManagerArray = ["Gitee", "GitLab", "GitHub"],
			downloadBSPToolVersions = [],
			downloadBSPCommitID = "",
			dialogContent,
			validateDialogNameAndPath,
			projectLocationHistorySelect = "",
			projectLocationHistoryText = "",
			projectBrowseButtonText = "",
			projectLocationArray = [],
			bResult,
			buttonOk,
			buttonBrowse,
			recordedUIlanguage = $.ajax({ url: "NuToolSetup.txt", async: false }).responseText,
			reocrdedPorjectName = "",
			recordedProjectLocation = "",
			recordedProjectLocationHistory = "",
			recordedCheckBSPCompatibility = "",
			recordedCheckProjfile = "",
			recordedCheckCppcmd = "",
			recordedCheckRename = "",
			recordedCheckAStyle = "",
			recordedChecModularizeCode = "",
			precedingPath = "";

		validateDialogNameAndPath = function (projectName, projectPath) {
			var ii,
				maxII,
				invalidCharArray = ['*', '?', '"', '<', '>', '|'],
				localChar,
				bResult = true;

			for (ii = 0, maxII = invalidCharArray.length; ii < maxII; ii += 1) {
				localChar = invalidCharArray[ii];
				if (projectPath.indexOf(invalidCharArray[ii]) !== -1) {
					showAlertDialog("工程路径不应该包含" + localChar + "。请修正它。",
						"專案路徑不應該包含" + localChar + "。請修正它。",
						"The project path should not contain " + localChar + ". Please fix it.");
					bResult = false;
					break;
				}
			}
			invalidCharArray.push('\\');
			invalidCharArray.push('/');
			invalidCharArray.push(':');
			for (ii = 0, maxII = invalidCharArray.length; ii < maxII; ii += 1) {
				localChar = invalidCharArray[ii];
				if (projectName.indexOf(localChar) !== -1) {
					showAlertDialog("工程名称不应该包含" + localChar + "。请修正它。",
						"專案名稱不應該包含" + localChar + "。請修正它。",
						"The project name should not contain " + localChar + ". Please fix it.");
					bResult = false;
					break;
				}
			}

			if (!projectPath.charAt(0).match(/^[a-zA-Z]/) ||
				!projectPath.charAt(1).match(/^[:]/) ||
				!projectPath.charAt(2).match(/^[\/\\]/)) {
				showAlertDialog("工程路径开头应为磁碟机代号、磁碟区分隔符号和元件分隔符号(C:\)。请修正它。",
					"專案路徑開頭應為磁碟機代號、磁碟區分隔符號和元件分隔符號(C:\)。請修正它。",
					"The project path should begin with a drive letter, a volume separator and a component separator (C:\). Please fix it.");
				bResult = false;
			}
			if (projectName.slice(-1).match(/^[ .]/)) {
				showAlertDialog("工程名称不应以空格或句号结尾。请修正它。",
					"專案名稱不應以空格或句號結尾。請修正它。",
					"The project name should not end with a space or peroid. Please fix it.");
				bResult = false;
			}
			return bResult;
		};

		buildReviewReportTable = function () {
			// build the new table
			if (!$("#generateCodeDialogTabs")[0]) {
				dialogContent = '<div id="generateCodeDialogTabs"><ul>';
				dialogContent += '<li><a href="#generateCodeDialogTabs_Pin">' + sTitle_Pin_inner + '</a></li>';
				dialogContent += '<li><a href="#generateCodeDialogTabs_Clock">' + sTitle_Clock_inner + '</a></li></ul>';
				dialogContent += '<div id="generateCodeDialogTabs_Pin"></div>';
				dialogContent += '<div id="generateCodeDialogTabs_Clock"></div>';
				dialogContent += '</div>';
				$(dialogContent).insertAfter($("#generateCodeDialogMainPart_div"));
			}
			// build reviewReportTable from PinConfigure
			tableDataArray_Pin = NUTOOL_PIN.get_pin_descriptions();
			if (tableDataArray_Pin.length > 10) {
				reviewReportTableHeight = "282px";
			}
			else {
				reviewReportTableHeight = "100%";
			}
			if (tableDataArray_Pin.length > 0) {
				reviewReportTable_Pin = new Tabulator("#generateCodeDialogTabs_Pin", {
					height: reviewReportTableHeight, // set height of table (in CSS or here), this enables the Virtual DOM and improves render speed dramatically (can be any valid css height value)
					data: tableDataArray_Pin, //assign data to table
					layout: "fitColumns", //fit columns to width of table
					columns: [ //Define Table Columns
						{ title: sTitle_Pin_inner, field: "pin", headerFilter: true },
						{ title: sTitle_Description_inner, field: "description", headerFilter: true },
						{ title: sTitle_UserDefined_inner, field: "userDefined", headerFilter: true, editor: true, validator: ["regex:^[a-zA-Z0-9 _]+$", "maxLength:30"], tooltip: sTooltip_inner }
					],
					cellEdited: function (cell) {
						NUTOOL_PIN.setReviewReportTable(cell._cell.row.data.pinNumber, cell._cell.row.data.description, cell._cell.value);
					},
					langs: {
						"Simplified": {
							"headerFilters": {
								"default": "过滤",
							}
						},
						"Traditional": {
							"headerFilters": {
								"default": "過濾...",
							}
						},
						"English": {
							"headerFilters": {
								"default": "filter...",
							}
						}
					}
				});
				if (g_userSelectUIlanguage.indexOf("Simplified") !== -1) {
					reviewReportTable_Pin.setLocale("Simplified");
				}
				else if (g_userSelectUIlanguage.indexOf("Traditional") !== -1) {
					reviewReportTable_Pin.setLocale("Traditional");
				}
				else {
					reviewReportTable_Pin.setLocale("English");
				}
			}
			else if (tableDataArray_Pin.length === 0) {
				reviewReportTable_Pin = new Tabulator("#generateCodeDialogTabs_Pin", {
					height: reviewReportTableHeight, // set height of table (in CSS or here), this enables the Virtual DOM and improves render speed dramatically (can be any valid css height value)
					placeholder: sNoData_inner //display message to user on empty table
				});
			}
			// build reviewReportTable from ClockConfigure
			tableDataArray_Clock = NUTOOL_CLOCK.concatenate_generated_code_begin();
			if (tableDataArray_Clock.length > 10) {
				reviewReportTableHeight = "282px";
			}
			else {
				reviewReportTableHeight = "100%";
			}
			if (tableDataArray_Clock.length > 0) {
				reviewReportTable_Clock = new Tabulator("#generateCodeDialogTabs_Clock", {
					height: reviewReportTableHeight, // set height of table (in CSS or here), this enables the Virtual DOM and improves render speed dramatically (can be any valid css height value)
					data: tableDataArray_Clock, //assign data to table
					layout: "fitColumns", //fit columns to width of table
					columns: [ //Define Table Columns
						{ title: sTitle_Module_inner, field: "module" },
						{ title: sTitle_BusClock_inner, field: "busClock" },
						{ title: sTitle_EngineClock_inner, field: "engineClock" }
					],
					langs: {
						"Simplified": {
							"headerFilters": {
								"default": "过滤",
							}
						},
						"Traditional": {
							"headerFilters": {
								"default": "過濾...",
							}
						},
						"English": {
							"headerFilters": {
								"default": "filter...",
							}
						}
					}
				});
				if (g_userSelectUIlanguage.indexOf("Simplified") !== -1) {
					reviewReportTable_Clock.setLocale("Simplified");
				}
				else if (g_userSelectUIlanguage.indexOf("Traditional") !== -1) {
					reviewReportTable_Clock.setLocale("Traditional");
				}
				else {
					reviewReportTable_Clock.setLocale("English");
				}
			}
		};

		downloadBSPFunction = function (BSPManager) {
			if (recordedUIlanguage === "Simplified Chinese") {
				recordedUIlanguage = "c";
			}
			else if (recordedUIlanguage === "Traditional Chinese") {
				recordedUIlanguage = "t";
			}
			else {
				recordedUIlanguage = "e";
			}

			if (NUTOOL_PER.g_cfg_downloadBSP.commitID.hasOwnProperty(NUTOOL_PER.g_toolVersion)) {
				downloadBSPCommitID = NUTOOL_PER.g_toolVersion;
			}
			else {
				downloadBSPToolVersions = getPropertyNames(NUTOOL_PER.g_cfg_downloadBSP.commitID);
				downloadBSPToolVersions.sort(natualSort);
				downloadBSPCommitID = downloadBSPToolVersions[0];
				for (i = 0, max = downloadBSPToolVersions.length; i < max; i++) {
					switch (versionCompare(NUTOOL_PER.g_toolVersion.toUpperCase().sliceAfterX('V'), downloadBSPToolVersions[i].toUpperCase().sliceAfterX('V'))) {
						case 1:
							downloadBSPCommitID = downloadBSPToolVersions[i];
							break;
						default:
						case -1:
							i = max;
							break;
					}
				}
			}
			downloadBSPCommitID = NUTOOL_PER.g_cfg_downloadBSP.commitID[downloadBSPCommitID];
			try { external.downloadBSPFromJS(NUTOOL_PER.g_toolVersion, BSPManager, NUTOOL_PER.g_cfg_downloadBSP.repository, downloadBSPCommitID, recordedUIlanguage); } catch (err) { }

			// [Workaround]
			if(g_bWebVersion) {
				numicroLowerCaseBSP = ["NUC1262BSP"];
				numicroM23FamilyBSP = ["M2351BSP", "M2354BSP", "M251BSP", "M261BSP", "NUC1262BSP"];
				numicroM4FamilyBSP  = ["M451BSP",  "M4521BSP", "M471BSP", "M480BSP", "M472_442BSP", "NUC505BSP"];
				var urlToOpen = "https://" + BSPManager.toLowerCase() + ".com/OpenNuvoton/";
				var repository = NUTOOL_PER.g_cfg_downloadBSP.repository.toUpperCase();
				if(BSPManager.toLowerCase() === "gitlab"){
					if(numicroM23FamilyBSP.includes(repository)){
						urlToOpen += "NuMicro-M23-Family/";
					}
					else if(numicroM4FamilyBSP.includes(repository)){
						urlToOpen += "NuMicro-M4-Family/";
					}
					else {
						urlToOpen += "NuMicro-M0-Family/";
					}
				}
				urlToOpen += (repository + "/tree/" + downloadBSPCommitID);
				window.open(urlToOpen);
			};
		};

		// return unless alpaca finished building
		if (!checkAlpacaReady()) {
			return;
		}
		// prevent the user from generating wrong code
		if (!g_bAlpacaValidationResult) {
			if (typeof NUTOOL_PIN !== 'undefined') {
				precedingPath = 'PeripheralConfigure//';
			}
			showWarningForFieldsInvalid(
				g_lastCheckedSnippetNode.slicePriorToX('_PeripheralConfigure'),
				function () {
					restorePerControlsToDefault(precedingPath + g_chipType + '//' + g_lastCheckedSnippetNode.slicePriorToX('_PeripheralConfigure') + '.txt');
					delete g_field1SubDIVsCache[g_lastCheckedSnippetNode.slicePriorToX('_PeripheralConfigure')];
					alpacaValidationSuccess();
					$('#perFunctionTree').jstree("uncheck_node", $('#' + g_lastCheckedSnippetNode));
				});
			return;
		}
		// entry
		if (typeof (recordedUIlanguage) !== 'undefined' && recordedUIlanguage.indexOf('UIlanguage:') !== -1) {
			reocrdedPorjectName = localStorage.getItem('ProjectName') || "";
			recordedProjectLocation = localStorage.getItem('ProjectLocation') || "";
			recordedProjectLocationHistory = localStorage.getItem('ProjectLocationHistory') || "";
			recordedCheckBSPCompatibility = recordedUIlanguage.sliceAfterX('CheckBSPCompatibility:');
			recordedCheckBSPCompatibility = recordedCheckBSPCompatibility.slicePriorToX('\r');
			if (recordedCheckBSPCompatibility === "Yes") {
				checkBSPCompatibilityChecked = "checked=true";
			}

			recordedCheckProjfile = recordedUIlanguage.sliceAfterX('CheckProjfile:');
			recordedCheckProjfile = recordedCheckProjfile.slicePriorToX('\r');
			if (recordedCheckProjfile === "No") {
				checkProjfileChecked = "";
			}

			recordedCheckCppcmd = recordedUIlanguage.sliceAfterX('CheckCppcmd:');
			recordedCheckCppcmd = recordedCheckCppcmd.slicePriorToX('\r');
			if (recordedCheckCppcmd === "No") {
				checkCppcmdChecked = "";
			}

			recordedCheckRename = recordedUIlanguage.sliceAfterX('CheckRename:');
			recordedCheckRename = recordedCheckRename.slicePriorToX('\r');
			if (recordedCheckRename === "No") {
				checkRenameChecked = "";
			}

			recordedCheckAStyle = recordedUIlanguage.sliceAfterX('CheckAStyle:');
			recordedCheckAStyle = recordedCheckAStyle.slicePriorToX('\r');
			if (recordedCheckAStyle === "No") {
				checkAStyleChecked = "";
			}

			recordedChecModularizeCode = recordedUIlanguage.sliceAfterX('CheckModularizeCode:');
			recordedChecModularizeCode = recordedChecModularizeCode.slicePriorToX('\r');
			if (recordedChecModularizeCode === "No" || recordedChecModularizeCode === "") {
				checkbox_ModularizeCodeChecked = "";
			}

			recordedUIlanguage = localStorage.getItem("UIlanguage");
			if (recordedUIlanguage === "Simplified Chinese") {
				title = "产生程式码";
				projectName = '工程名称';
				content = "请输入文件夹路径，例如 BSP\\...\\SampleCode，用于存放生成的代码:";
				content2 = "请注意，本软件不能取代技术参考手册或规格书。用户必须参考最新文档以确保正确性。";
				downloadBSPManagerText = "来自";
				projectLocationHistoryText = "或是您可以从最近的工程中选择一个";
				projectBrowseButtonText = "浏览";
				checkBSPCompatibilityText = "检查BSP兼容性";
				checkboxModularize = "模组化代码";
				checkboxReviewReport = "检阅报告";
				sTitle_Pin_inner = "脚位";
				sTitle_Clock_inner = "时脉",
					sTitle_Description_inner = "描述";
				sTitle_UserDefined_inner = "用户定义";
				sTooltip_inner = "仅限英文字母、数字和底线。\n最大输入长度为30。";
				sNoData_inner = "没有可用数据，因为尚未配置。";
				sTitle_Module_inner = "模块";
				sTitle_BusClock_inner = "汇流排频率";
				sTitle_EngineClock_inner = "引擎频率";
				buttonOk = "确定";
				buttonBrowse = "下载BSP";
			}
			else if (recordedUIlanguage === "Traditional Chinese") {
				title = "產生程式碼";
				projectName = '專案名稱';
				content = "請輸入資料夾路徑，例如 BSP\\...\\SampleCode，用於存放生成的程式碼:";
				content2 = "請注意，本軟件不能取代技術參考手冊或規格書。用戶必須參考最新文檔以確保正確性。";
				downloadBSPManagerText = "來自";
				projectLocationHistoryText = "或是您可以從最近的專案中選擇一個";
				projectBrowseButtonText = "瀏覽";
				checkBSPCompatibilityText = "檢查BSP兼容性";
				checkboxModularize = "模組化程式碼";
				checkboxReviewReport = "檢閱報告";
				sTitle_Pin_inner = "腳位";
				sTitle_Clock_inner = "時脈",
					sTitle_Description_inner = "描述";
				sTitle_UserDefined_inner = "用戶定義";
				sTooltip_inner = "僅限英文字母、數字和底線。\n最大輸入長度為30。";
				sNoData_inner = "沒有可用數據，因為尚未配置。";
				sTitle_Module_inner = "模組";
				sTitle_BusClock_inner = "匯流排頻率";
				sTitle_EngineClock_inner = "引擎頻率";
				buttonOk = "確定";
				buttonBrowse = "下載BSP";
			}
			else {
				title = "Generate Code";
				projectName = 'Project Name';
				content = "Please input a folder path, e.g. BSP\\...\\SampleCode, for storing the generated code:";
				content2 = "Please note that the tool is not a replacement for the technical reference manual or datasheet. The user must refer to the latest documentation for the correctness.";
				downloadBSPManagerText = "From ";
				projectLocationHistoryText = "Or you can choose a folder from recent projects";
				projectBrowseButtonText = "Browse";
				checkBSPCompatibilityText = "Check BSP Compatibility";
				checkboxModularize = "Modularize Code";
				checkboxReviewReport = "Review Report";
				sTitle_Pin_inner = "Pin";
				sTitle_Clock_inner = "Clock",
					sTitle_Description_inner = "Description";
				sTitle_UserDefined_inner = "User Defined";
				sTooltip_inner = "English letters, digits and underscores only.\nMaximum length of input is 30.";
				sNoData_inner = "No data available because not configured yet.";
				sTitle_Module_inner = "Module";
				sTitle_BusClock_inner = "Bus Clock";
				sTitle_EngineClock_inner = "Engine Clock";
				buttonOk = "Confirm";
				buttonBrowse = "Download BSP";
			}
		}
		else {
			title = "Generate Code";
			projectName = 'Project Name';
			content = "Please input a folder path, e.g. BSP\\...\\SampleCode, for storing the generated code:";
			content2 = "Please note that the tool is not a replacement for the technical reference manual or datasheet. The user must refer to the latest documentation for the correctness.";
			downloadBSPManagerText = "BSP From ";
			projectLocationHistoryText = "Or you can choose a folder from recent projects";
			projectBrowseButtonText = "Browse";
			checkBSPCompatibilityText = "Check BSP Compatibility";
			checkboxModularize = "Modularize Code";
			checkboxReviewReport = "Review Report";
			buttonOk = "Confirm";
			buttonBrowse = "Download BSP";
		}
		if (reocrdedPorjectName.trim() === "") {
			reocrdedPorjectName = "MyProject";
		}
		if (recordedProjectLocationHistory.trim() !== "") {
			projectLocationArray = recordedProjectLocationHistory.split('>');
			projectLocationHistorySelect = '<br /><select id="generateCodeDialogSelect" style="width: 450px;height:30px;"><option value="default">' + projectLocationHistoryText + '</option>';
			for (i = 0, max = projectLocationArray.length - 1; i < max; i++) {
				projectLocationHistorySelect += '<option value="' + projectLocationArray[i] + '">' + projectLocationArray[i] + '</option>';
			}
			projectLocationHistorySelect += '</select>';
		}

		if (checkboxModularizeNotSupportedList.indexOf(g_chipType) === -1 &&
			NUTOOL_PIN.g_cfg_gpiosDefines.length !== 0 &&
			(NUTOOL_PIN.g_cfg_gpiosDefines[0].f.length > 1 && NUTOOL_PIN.g_cfg_gpiosDefines[0].f[1].indexOf("GPIO:") === 0)) {
			checkboxModularizeType = "checkbox";
		}
		else {
			checkboxModularize = "";
			checkboxModularizeType = "hidden";
			checkbox_ModularizeCodeChecked = "";
		}

		// close the last dialog
		removeAlldialogs();
		// check the requirement of pin and clock
		prepare_generated_code();
		// check the correctness of PinConfigure and ClockConfigure
		showModulesNeedChecking();
		// JQuery sets the autofocus on the first input that is found. So play it sneaky by creating a "fake" input at the last line of your dialog
		if (g_bDevelopingTool) {
			dialogContent = '<div id="generateCodeDialogMainPart_div"><label>' + projectName + ': <input type="text" id="inputText_projectName" value="' + reocrdedPorjectName + '" style="width:250px;height:30px;"></label><br /><br /><label><p>' + content + '</p></label><label><input id="generateCodeDialogInput" type="text" style="width:370px;height:30px;" value="' + recordedProjectLocation + '"><button id="generateCodeDialogBrowseFolder" style="width:80px;height:30px;">' + projectBrowseButtonText + '</button></label>' + projectLocationHistorySelect + '<br /><br /><label><input type="checkbox" id="projfileCheckbox" ' + checkProjfileChecked + '/> Run Projfile</label><br /><label><input type="checkbox" id="cppcmdCheckbox" ' + checkCppcmdChecked + '/> Run Cppcmd</label><br /><label><input type="checkbox" id="astyleCheckbox" ' + checkAStyleChecked + '/> Run AStyle</label><br /><label><input type="checkbox" id="renameCheckbox" ' + checkRenameChecked + '/> Run Rename</label><p>' + content2 + '</p><label><input type="checkbox" id="checkbox_ModularizeCode" ' + checkbox_ModularizeCodeChecked + '/> ' + checkboxModularize + '</label><input type="text" size="1" style="position:relative;top:-5000px;"/></div>';
		}
		else {
			dialogContent = '<div id="generateCodeDialogMainPart_div"><label>' + projectName + ': <input type="text" id="inputText_projectName" value="' + reocrdedPorjectName + '" style="width:250px;height:30px;"></label><br /><br /><label><p>' + content + '</p></label><label><input id="generateCodeDialogInput" type="text" style="width:370px;height:30px;" value="' + recordedProjectLocation + '"><button id="generateCodeDialogBrowseFolder" style="width:80px;height:30px;">' + projectBrowseButtonText + '</button></label>' + projectLocationHistorySelect + '<br /><br /><p>' + content2 + '</p><label><input type="checkbox" id="checkbox_ModularizeCode" ' + checkbox_ModularizeCodeChecked + '/> ' + checkboxModularize + '</label><input type="text" size="1" style="position:relative;top:-5000px;"/></div>';
		}
		$('<div id="generateCodeDialog">' + dialogContent + '</div>').dialog({
			modal: true,
			resizable: false,
			title: title,
			width: 500,
			height: 'auto',
			show: 'fade',
			hide: 'fade',
			close: function () {
				$("#generateCodeDialog").dialog("destroy");
			},
			create: function (e, ui) {
				// add the button of Download BSP
				downloadBSPManagerSelect += "<div class='btn-group dropup'>";
				downloadBSPManagerSelect += "<button type='button' class='ui-widget ui-state-default ui-corner-all ui-button-text-only dropdown-toggle' data-toggle='dropdown' style='height:31px;'>" + buttonBrowse + "  <span class='caret'></span></button>";
				downloadBSPManagerSelect += "<ul class='dropdown-menu' role='menu'>";
				for (i = 0, max = downloadBSPManagerArray.length; i < max; i++) {
					downloadBSPManagerSelect += "<li><a id=" + downloadBSPManagerArray[i] + ">" + downloadBSPManagerText + downloadBSPManagerArray[i] + "</a></li>";
				}
				downloadBSPManagerSelect += "</ul></div>";
				$(this).closest(".ui-dialog").find(".ui-dialog-buttonset").prepend(downloadBSPManagerSelect);
				// add the checkbox of ReviewReport
				$("<label class='generateCodeDialog_ReviewReport' ><input type='checkbox' id='checkbox_ReviewReport'/> " + checkboxReviewReport + "</label>").prependTo($(this).dialog("widget").find(".ui-dialog-buttonpane"));
			},
			buttons: [
				{
					id: "generateCodeDialog_buttonOk",
					text: buttonOk,
					click: function () {
						$("#generateCodeDialog_buttonOk").button("disable");
						$("#generateCodeDialog_buttonDownload").button("disable");
						if ($('#inputText_projectName').val().trim() === "") {
							$('#inputText_projectName').val("MyProject");
						}
						if (validateDialogNameAndPath($('#inputText_projectName').val(), $("#generateCodeDialogInput").val())) {
							if (g_bDevelopingTool) {
								try { bResult = external.generateCodeFromJS($('#inputText_projectName').val(), $("#generateCodeDialogInput").val(), "checkVersionCheckbox:" + $("#checkVersionCheckbox").is(":checked") + "/projfileCheckbox:" + $("#projfileCheckbox").is(":checked") + "/cppcmdCheckbox:" + $("#cppcmdCheckbox").is(":checked") + "/renameCheckbox:" + $("#renameCheckbox").is(":checked") + "/astyleCheckbox:" + $("#astyleCheckbox").is(":checked") + "/CheckModularizeCode:" + $("#checkbox_ModularizeCode").is(":checked"), g_userHeader); } catch (err) { }
							}
							else {
								try { bResult = external.generateCodeFromJS($('#inputText_projectName').val(), $("#generateCodeDialogInput").val(), "checkVersionCheckbox:" + $("#checkVersionCheckbox").is(":checked") + "/projfileCheckbox:true/cppcmdCheckbox:true/renameCheckbox:true/astyleCheckbox:true" + "/CheckModularizeCode:" + $("#checkbox_ModularizeCode").is(":checked"), g_userHeader); } catch (err) { }
							}
							if (bResult) {
								// close the last dialog
								if ($("#generateCodeDialog").dialog("isOpen")) {
									$("#generateCodeDialog").dialog("destroy");
								}
							}
						}
						$("#generateCodeDialog_buttonOk").button("enable");
						$("#generateCodeDialog_buttonDownload").button("enable");
					}
				}
			]
		});
		// handle events
		$('#generateCodeDialogInput').keypress(function (e) {
			switch (e.which) {
				case 22: //ctrl + v
					$("#generateCodeDialogInput").val(window.clipboardData.getData("Text"));
					break;
			}
		});
		$('#generateCodeDialogBrowseFolder').click(function () {
			if ($('#inputText_projectName').val().trim() === "") {
				$('#inputText_projectName').val("MyProject");
			}
			try { external.generateCodeFromJS($('#inputText_projectName').val(), "generateCodeDialogInput:none", "checkVersionCheckbox:" + $("#checkVersionCheckbox").is(":checked") + "/projfileCheckbox:" + $("#projfileCheckbox").is(":checked") + "/cppcmdCheckbox:" + $("#cppcmdCheckbox").is(":checked") + "/renameCheckbox:" + $("#renameCheckbox").is(":checked") + "/astyleCheckbox:" + $("#astyleCheckbox").is(":checked") + "/CheckModularizeCode:" + $("#checkbox_ModularizeCode").is(":checked"), g_userHeader); } catch (err) { }
			if (NUTOOL_PER.g_perFunctionString !== "" &&
				NUTOOL_PER.g_perFunctionString.indexOf(':') !== -1) {
				$("#generateCodeDialogInput").val(NUTOOL_PER.g_perFunctionString);
			}
			$("#generateCodeDialog").focus();

			// [Workaround]
			if(g_bWebVersion) {
				$('#bspForGenCode').trigger('click');
			}
		});
		$("#generateCodeDialogSelect").change(function () {
			if ($("#generateCodeDialogSelect").val() !== "default") {
				$("#generateCodeDialogInput").val($("#generateCodeDialogSelect").val());
				$("#generateCodeDialogSelect").val($("#generateCodeDialogSelect option:first-child").val());
			}
		});
		$("#checkbox_ReviewReport").change(function () {
			if ($('#checkbox_ReviewReport').is(':checked')) {
				buildReviewReportTable();
				$("#generateCodeDialogTabs").tabs();
				$("#generateCodeDialogTabs ul li").css({ 'width': '70px' });
				$('#generateCodeDialogMainPart_div').hide();
				$(this).closest(".ui-dialog").find(".ui-dialog-buttonset").hide();
			}
			else {
				// remove the last review tables
				$('#generateCodeDialogTabs').remove();
				$('#generateCodeDialogMainPart_div').show();
				$(this).closest(".ui-dialog").find(".ui-dialog-buttonset").show();
			}
		});
		$("#GitHub").click(function () {
			downloadBSPFunction('GitHub');
		});
		$("#GitLab").click(function () {
			downloadBSPFunction('GitLab');
		});
		$("#Gitee").click(function () {
			downloadBSPFunction('Gitee');
		});
	}

	function restoreToDefault() {
		var i,
			max,
			moduleNames = getPropertyNames(g_module_snippet),
			currentNode,
			childNode,
			precedingPath = "",
			saved_currentSnippetFilePath = g_currentSnippetFilePath;

		function f1(index, listItem) {
			childNode = $(listItem).attr("id");
			preprocessTagFile(childNode.slicePriorToX('_PeripheralConfigure'));
			restorePerControlsToDefault(precedingPath + g_chipType + '//' + childNode.slicePriorToX('_PeripheralConfigure') + '.txt');
			if ($("#" + childNode).hasClass('jstree-checked')) {
				$('#perFunctionTree').jstree("uncheck_node", $('#' + childNode));
			}
		}

		// return unless alpaca finished building
		if (!checkAlpacaReady()) {
			return;
		}

		if (typeof NUTOOL_PIN !== 'undefined') {
			precedingPath = 'PeripheralConfigure//';
		}

		g_generatedCodeFromPerString = "";
		moduleNames.sort(natualSort);
		for (i = 0, max = moduleNames.length; i < max; i += 1) {
			currentNode = moduleNames[i];
			if ($("#" + currentNode + '_PeripheralConfigure').find("li").length > 0) {
				$("#" + currentNode + '_PeripheralConfigure').find("li").each(f1);
			}
			else {
				preprocessTagFile(currentNode.slicePriorToX('_PeripheralConfigure'));
				restorePerControlsToDefault(precedingPath + g_chipType + '//' + currentNode + '.txt');
				currentNode = currentNode.replaceSpecialCharacters() + '_PeripheralConfigure';
				if ($("#" + currentNode).hasClass('jstree-checked')) {
					$('#perFunctionTree').jstree("uncheck_node", $('#' + currentNode));
				}
			}
		}

		g_currentSnippetFilePath = saved_currentSnippetFilePath;

		moduleNames = NUTOOL_PER.g_cfg_thirdPartyLibs;
		for (i = 0, max = moduleNames.length; i < max; i += 1) {
			currentNode = moduleNames[i].replaceSpecialCharacters() + '_PeripheralConfigure';
			if ($("#" + currentNode).hasClass('jstree-checked')) {
				$('#perFunctionTree').jstree("uncheck_node", $('#' + currentNode));
			}
		}

		for (i = 0, max = g_field1SubDIVs.length; i < max; i += 1) {
			if (typeof ($("#" + g_field1SubDIVs[i])) !== 'undefined' &&
				$("#" + g_field1SubDIVs[i]).alpaca("exists")) {
				if (!g_bReadyForRelease && window.console) { window.console.log("In initializeAll, remove: " + g_field1SubDIVs[i]); }
				$("#" + g_field1SubDIVs[i]).alpaca("destroy");
				$("#" + g_field1SubDIVs[i]).remove();
			}
		}
		g_field1SubDIVs = [];
		g_field1SubDIVsCache = {};

		$("#field1_canvas").remove();
		$("#field1_anchor").remove();
		buildControlContainer();
	}

	function redrawForResizingDialog() {
		decideNuToolSetup();

		// adjust the size of the relevant UI elements
		if ($('#perFunctionTree').css('display') === 'none') {
			$('#CodeGeneratorContainer').width(g_Dialog_Width);
			$('#CodeGeneratorContainer').height(g_Dialog_Height);
		}
		else {
			if (g_thirdPartyLibTreeHeight !== 0) {
				$('#perFunctionTree').height(g_NUC_TreeView_Height - $("#ChipType_Peripheral").height() - $("#MCU_Peripheral").height() - $("#supportedperFunctions").height() - g_thirdPartyLibTreeHeight - 20);
			}
			else {
				$('#perFunctionTree').height(g_NUC_TreeView_Height - $("#ChipType_Peripheral").height() - $("#MCU_Peripheral").height() - $("#supportedperFunctions").height());
			}
			$('#CodeGeneratorContainer').width(g_Dialog_Width - g_NUC_TreeView_Width + 16);
			$('#CodeGeneratorContainer').height(g_Dialog_Height);
		}
	}

	function recordConfig() {
	}

	function closeAPP() {
		if ($("#" + g_lastCheckedSnippetNode).hasClass('jstree-checked') &&
			$("#" + g_module_snippet_buttonId[g_lastCheckedSnippetNode.slicePriorToX('_PeripheralConfigure')]).alpaca("exists")) {
			$("#" + g_module_snippet_buttonId[g_lastCheckedSnippetNode.slicePriorToX('_PeripheralConfigure')]).alpaca("get").form.getButtonEl("submit").click();
		}
		try { external.closeFromJS(); } catch (err) { }
	}

	function settings() {
		var title,
			content1,
			engiish,
			simplifiedChinese,
			traditionalChinese,
			stringDialogDIV,
			engiishChecked = "",
			simplifiedChineseChecked = "",
			traditionalChineseChecked = "",
			buttonOk,
			buttonCancel,
			recordedUIlanguage,
			local_currentTool = g_currentTool,
			$ChipType_span_Peripheral = $("#ChipType_span_Peripheral"),
			$MCU_span_Peripheral = $("#MCU_span_Peripheral"),
			$supportedthirdPartyLibs_span = $("#supportedthirdPartyLibs_span"),
			$supportedperFunctions_span = $("#supportedperFunctions_span");

		recordedUIlanguage = $.ajax({ url: "NuToolSetup.txt", async: false }).responseText;

		//if ($('#rootTree_Peripheral').is(':visible')) {
		if (typeof (recordedUIlanguage) !== 'undefined' && recordedUIlanguage.indexOf('UIlanguage:') !== -1) {
			recordedUIlanguage = recordedUIlanguage.sliceAfterX('UIlanguage:').slicePriorToX('\r');
			if (recordedUIlanguage === "Simplified Chinese") {
				title = "设定";
				content1 = "从下面选取一个语言显示在操作介面上。";
				engiish = "英文";
				simplifiedChinese = "简体中文";
				traditionalChinese = "繁体中文";
				simplifiedChineseChecked = "checked";
				buttonOk = "确定";
				buttonCancel = "离开";
			}
			else if (recordedUIlanguage === "Traditional Chinese") {
				title = "設定";
				content1 = "從下面選取一個語言顯示在操作介面上。";
				engiish = "英文";
				simplifiedChinese = "简體中文";
				traditionalChinese = "繁體中文";
				traditionalChineseChecked = "checked";
				buttonOk = "確定";
				buttonCancel = "離開";
			}
			else {
				title = "Settings";
				content1 = "Select one of the following languages displayed in UI.";
				engiish = "English";
				simplifiedChinese = "Simplified Chinese";
				traditionalChinese = "Traditional Chinese";
				engiishChecked = "checked";
				buttonOk = "Confirm";
				buttonCancel = "Leave";
			}
		}
		else {
			title = "Settings";
			content1 = "1. Select one of the following languages displayed in UI.";
			engiish = "English";
			simplifiedChinese = "Simplified Chinese";
			traditionalChinese = "Traditional Chinese";
			engiishChecked = "checked";
			buttonOk = "Confirm";
			buttonCancel = "Leave";
		}

		// close the last dialog
		removeAlldialogs();

		stringDialogDIV = '<div id="languageDialog"><p>' + content1 + '</p><input type="radio" id="engiish" value="English" name="UIlanguage" ' + engiishChecked + '><label for="engiish">' + engiish + '</label><br /><input type="radio" id="simplifiedChinese" value="Simplified Chinese" name="UIlanguage" ' + simplifiedChineseChecked + '><label for="simplifiedChinese">' + simplifiedChinese + '</label><br /><input type="radio" id="traditionalChinese" value="Traditional Chinese" name="UIlanguage" ' + traditionalChineseChecked + '><label for="traditionalChinese">' + traditionalChinese + '</label><br /><input type="text" size="1" style="position:relative;top:-5000px;"/></div>';
		$(stringDialogDIV).dialog({
			modal: false,
			draggable: false,
			resizable: false,
			title: title,
			width: 500,
			height: 'auto',
			show: 'fade',
			hide: 'fade',
			close: function () {
				$("#languageDialog").dialog("destroy");
			},
			buttons: [
				{
					text: buttonOk,
					click: function () {
						// iterate radio buttons
						$("input").each(function () {
							if (this.name === "UIlanguage" && this.checked === true) {
								g_userSelectUIlanguage = $(this).val();
								if (g_userSelectUIlanguage.indexOf("Simplified") !== -1) {
									$ChipType_span_Peripheral.text('晶片系列:');
									$MCU_span_Peripheral.text('型号:');
									$supportedthirdPartyLibs_span.text('第三方函式库');
									$supportedperFunctions_span.text('外设功能');
									$("#field1_span").html("欢迎来到NuTool - CodeGenerator。<br />您可以在这里配置外设功能并生成源代码。<br />玩得开心！ (观看快速上手&#128214;)");
								}
								else if (g_userSelectUIlanguage.indexOf("Traditional") !== -1) {
									$ChipType_span_Peripheral.text('晶片系列:');
									$MCU_span_Peripheral.text('型號:');
									$supportedthirdPartyLibs_span.text('第三方函式庫');
									$supportedperFunctions_span.text('週邊功能');
									$("#field1_span").html("歡迎來到NuTool - CodeGenerator。<br />您可以在這裡配置週邊功能並生成原始碼。<br />玩得開心！ (觀看快速上手&#128214;)");
								}
								else {
									$ChipType_span_Peripheral.text('Chip Series:');
									$MCU_span_Peripheral.text('Part No.:');
									$supportedthirdPartyLibs_span.text('Third Party Libraries');
									$supportedperFunctions_span.text('Peripheral Functions');
									$("#field1_span").html("Welcome to NuTool - CodeGenerator.<br />You can configure peripheral functions and generate code here.<br />Have fun! (Watch Quick Start &#128214;)");
								}

								window.external.saveUIlanguage("UIlanguage:" + g_userSelectUIlanguage);
								if (typeof NUTOOL_PIN !== 'undefined') {
									showPinConfigure();
									NUTOOL_PIN.changeUIlanguage();
									showClockConfigure();
									NUTOOL_CLOCK.changeUIlanguage();
								}

								if (local_currentTool === 'PinConfigure') {
									showPinConfigure();
								}
								else if (local_currentTool === 'ClockConfigure') {
									showClockConfigure();
								}
								else {
									showPeripheralConfigure();
								}
							}
						});

						// close the last dialog
						if ($("#languageDialog").dialog("isOpen")) {
							$("#languageDialog").dialog("destroy");
						}
					}
				},
				{
					text: buttonCancel,
					click: function () {
						if (g_userSelectUIlanguage === "") {
							g_userSelectUIlanguage = "English";
						}
						// close the last dialog
						if ($("#languageDialog").dialog("isOpen")) {
							$("#languageDialog").dialog("destroy");
						}
					}
				}
			]
		});
		//}
	}

	function executePDFfail() {
		showAlertDialog("您的电脑不能执从PDF档。请安装必要的软件来支援它。",
			"您的電腦不能執從PDF檔。請安裝必要的軟件來支援它。",
			"Your PC is incapable of executing the PDF files. Please install a necessary software to support it");
	}

	function generateCodeFail() {
		showAlertDialog("在产生程式过程中出了点问题。",
			"在產生程式碼過程中出了點問題。",
			"Something was wrong during generating code.");
	}

	function alpacaValidationSuccess() {
		g_bAlpacaValidationResult = true;
	}

	function alpacaValidationFailure() {
		g_bAlpacaValidationResult = false;
	}
	///////////////////////////////////////////////////////////public API/////////////////////////////////////////////////////////////
	NUTOOL_PER = {
		getg_chipType: function () {
			return g_chipType;
		},
		getg_partNumber_package: function () {
			return g_partNumber_package;
		},
		getg_generatedCodeFromPerString: function () {
			return g_generatedCodeFromPerString;
		},
		getg_enabledThirdPartyLibString: function () {
			return g_enabledThirdPartyLibString;
		},
		getg_enabledPeripheralFunctionString: function () {
			return g_enabledPeripheralFunctionString;
		},
		getg_userSelectUIlanguage: function () {
			return g_userSelectUIlanguage;
		},
		getg_currentSnippetFilePath: function () {
			return g_currentSnippetFilePath;
		},
		getg_updatedSnippetFile: function () {
			return g_updatedSnippetFile;
		},
		getg_cfg_projectLoaction: function () {
			var returnValue;

			if (typeof NUTOOL_PER.g_cfg_projectLoaction[g_partNumber_package.slicePriorToX('(')] !== 'undefined') {
				returnValue = NUTOOL_PER.g_cfg_projectLoaction[g_partNumber_package.slicePriorToX('(')];
			}
			else if (typeof NUTOOL_PER.g_cfg_projectLoaction.ByDefault !== 'undefined') {
				returnValue = NUTOOL_PER.g_cfg_projectLoaction.ByDefault;
			}
			else {
				returnValue = NUTOOL_PER.g_cfg_projectLoaction;
			}
			return returnValue;
		},
		getg_cfg_thidrPartyLibLoaction: function () {
			return NUTOOL_PER.g_cfg_thidrPartyLibLoaction;
		},
		getg_currentTool: function () {
			return g_currentTool;
		},
		getg_toolVersion: function () {
			return NUTOOL_PER.g_toolVersion;
		},
		getg_bDevelopingTool: function () {
			return g_bDevelopingTool;
		},
		////for functional test////
		getg_perControls: function () {
			return g_perControls;
		},
		getg_module_snippet_code: function () {
			return g_module_snippet_code;
		},
		////for react web version////
		setg_variables : function (target, newValue) {
			eval(`${target}  =  newValue`);
		},
		getg_variables : function (target) {
			return eval(`${target}`);
		},
		replaceTag: replaceTag,
		removeAllTags: removeAllTags,
		g_bFunctionalTesting: false,
		g_postRender_f1: {},
		g_postRender_control: {},
		showModulesNeedChecking: showModulesNeedChecking,
		/////////////////////////////////////////////////////////////////////////////////////
		checkAlpacaReady: checkAlpacaReady,
		decideNewChipType: decideNewChipType,
		decideNewPartNumberType: decideNewPartNumberType,
		chipTypeToChipSeries: chipTypeToChipSeries,
		showPinConfigure: showPinConfigure,
		showClockConfigure: showClockConfigure,
		showPeripheralConfigure: showPeripheralConfigure,
		showCodeOnly: showCodeOnly,
		restoreToDefault: restoreToDefault,
		redrawForResizingDialog: redrawForResizingDialog,
		concatenate_generated_cfg: concatenate_generated_cfg,
		concatenate_generated_code: concatenate_generated_code,
		loadConfig: loadConfig,
		loadConfig_core: loadConfig_core,
		readTreeContent: readTreeContent,
		saveConfig: saveConfig,
		recordConfig: recordConfig,
		closeAPP: closeAPP,
		settings: settings,
		generateCode: generateCode,
		executePDFfail: executePDFfail,
		generateCodeFail: generateCodeFail,
		alpacaValidationSuccess: alpacaValidationSuccess,
		alpacaValidationFailure: alpacaValidationFailure,
		g_readConfigFilePath: "", // for DISPATCH_PROPERTYPUT
		g_perFunctionString: ""   // for DISPATCH_PROPERTYPUT
	};
}(NUTOOL_PER, this));
