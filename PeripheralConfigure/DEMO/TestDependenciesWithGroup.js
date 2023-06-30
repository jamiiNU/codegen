(function($) {
	var dependenciesShow = true;

	//return;
	///////////////////////////////////////////// Select ////////////////////////////////////////////////////////////
	module("Dependencies Tests for Select Fields.");
	test("Single Test", function() {
		var testElement = S('#field1_sub0 input[name=group1_UART1BaudrateInteger]'),
			dependenciesElement = S('#field1_sub0 select[name=group1_UART0BaudrateSelect]');

		equal(dependenciesElement.length, 1, 'control group1_UART0BaudrateSelect found.');
		equal(dependenciesElement.val(), "9600", 'control group1_UART0BaudrateSelect value 9600 checked.');
		if (testElement.length) {
			ok(true, 'test control found:' + testElement.length);
		}
		else {
			ok(false, 'test control not found');
		}
		equal(testElement.is(":visible"), false, 'control group1_UART1BaudrateInteger hidden.');
		if (dependenciesShow) {
			dependenciesElement[0].value = "4800";
			dependenciesElement.change();
			equal(dependenciesElement.val(), "4800", 'control group1_UART0BaudrateSelect value 4800 checked.');
			S.wait(500, function() {
				equal(testElement.is(":visible"), true, 'control group1_UART1BaudrateInteger shown.');
			});
		}
	});
	test("Boolean Test", function() {
		var testElement = S('#field1_sub0 select[name=group1_TIMER0OutputPinSelect]'),
			dependenciesElement = S('#field1_sub0 select[name=group1_TIMER0ModeSelect]');

		equal(dependenciesElement.length, 1, 'control group1_TIMER0ModeSelect found.');
		equal(dependenciesElement.val(), "TIMER_ONESHOT_MODE", 'control group1_TIMER0ModeSelect value TIMER_ONESHOT_MODE checked.');
		if (testElement.length) {
			ok(true, 'test control found:' + testElement.length);
		}
		else {
			ok(false, 'test control not found');
		}
		equal(testElement.is(":visible"), false, 'control group1_TIMER0OutputPinSelect hidden.');
		if (dependenciesShow) {
			dependenciesElement[0].value = "TIMER_PERIODIC_MODE";
			dependenciesElement.change();
			equal(dependenciesElement.val(), "TIMER_PERIODIC_MODE", 'control group1_TIMER0ModeSelect value TIMER_PERIODIC_MODE checked.');
			S.wait(500, function() {
				equal(testElement.is(":visible"), true, 'control group1_TIMER0OutputPinSelect shown.');
			});
		}
	});
	test("Object of Array Test", function() {
		var testElement = S('#field1_sub0 select[name=group1_PDMACH2Destination1]'),
			dependenciesElement = S('#field1_sub0 select[name=group1_PDMACH2Source]');

		equal(dependenciesElement.length, 1, 'control group1_PDMACH2Source found.');
		equal(dependenciesElement.val(), "PDMA_MEM", 'control group1_PDMACH2Source value PDMA_MEM checked.');
		if (testElement.length) {
			ok(true, 'test control found:' + testElement.length);
		}
		else {
			ok(false, 'test control not found');
		}
		equal(testElement.is(":visible"), false, 'control group1_PDMACH2Destination1 hidden.');
		if (dependenciesShow) {
			dependenciesElement[0].value = "PDMA_UART0_RX";
			dependenciesElement.change();
			equal(dependenciesElement.val(), "PDMA_UART0_RX", 'control group1_PDMACH2Source value PDMA_UART0_RX checked.');
			S.wait(500, function() {
				equal(testElement.is(":visible"), true, 'control group1_PDMACH2Destination1 shown.');
			});
		}
	});
	///////////////////////////////////////////// Radio ////////////////////////////////////////////////////////////
	module("Dependencies Tests for Radio Fields.");
	test("Single Test", function() {
		var testElement = S('#field1_sub0 div[name=group1_UART1EnableINTCheckbox]'),
			dependenciesElement = S('#field1_sub0 input:radio[name=group1_UART0BaudrateRadio]'),
			dependenciesCheckedElement = S('#field1_sub0 input:radio[name=group1_UART0BaudrateRadio]:checked');

		equal(dependenciesElement.length, 9, 'control group1_UART0BaudrateRadio found.');
		equal(dependenciesCheckedElement.length, 1, "control group1_UART0BaudrateRadio Checked found.");
		equal(dependenciesCheckedElement.val(), "57600", 'control group1_UART0BaudrateRadio value 57600 checked.');
		if (testElement.length) {
			ok(true, 'test control found:' + testElement.length);
		}
		else {
			ok(false, 'test control not found');
		}
		equal(testElement.is(":visible"), false, 'control group1_UART1EnableINTCheckbox hidden.');
		if (dependenciesShow) {
			dependenciesElement[4].checked = false;
			dependenciesElement[5].checked = true;
			dependenciesElement.change();
			dependenciesCheckedElement = S('#field1_sub0 input:radio[name=group1_UART0BaudrateRadio]:checked');
			equal(dependenciesCheckedElement.length, 1, "control group1_UART0BaudrateRadio Checked found.");
			equal(dependenciesCheckedElement.val(), "115200", 'control group1_UART0BaudrateRadio value 115200 checked.');
			S.wait(500, function() {
				equal(testElement.is(":visible"), true, 'control group1_UART1EnableINTCheckbox shown.');
			});
		}
	});
	test("Boolean Test", function() {
		var testElement = S('#field1_sub0 div[name=group1_CLK_DPDWKPIN0Checkbox]'),
			dependenciesElement = S('#field1_sub0 input:radio[name=group1_CLK_PowerDownModeRadio]'),
			dependenciesCheckedElement = S('#field1_sub0 input:radio[name=group1_CLK_PowerDownModeRadio]:checked');

		equal(dependenciesElement.length, 3, 'control group1_CLK_PowerDownModeRadio found.');
		equal(dependenciesCheckedElement.length, 1, "control group1_CLK_PowerDownModeRadio Checked found.");
		equal(dependenciesCheckedElement.val(), "CLK_PMUCTL_PDMSEL_PD", 'control group1_CLK_PowerDownModeRadio value CLK_PMUCTL_PDMSEL_PD checked.');
		if (testElement.length) {
			ok(true, 'test control found:' + testElement.length);
		}
		else {
			ok(false, 'test control not found');
		}
		equal(testElement.is(":visible"), false, 'control group1_CLK_DPDWKPIN0Checkbox hidden.');
		if (dependenciesShow) {
			dependenciesElement[0].checked = false;
			dependenciesElement[1].checked = true;
			dependenciesElement.change();
			dependenciesCheckedElement = S('#field1_sub0 input:radio[name=group1_CLK_PowerDownModeRadio]:checked');
			equal(dependenciesCheckedElement.length, 1, "control group1_CLK_PowerDownModeRadio Checked found.");
			equal(dependenciesCheckedElement.val(), "CLK_PMUCTL_PDMSEL_FWPD", 'control group1_CLK_PowerDownModeRadio value CLK_PMUCTL_PDMSEL_FWPD checked.');
			S.wait(500, function() {
				equal(testElement.is(":visible"), true, 'control group1_CLK_DPDWKPIN0Checkbox shown.');
			});
		}
	})
	///////////////////////////////////////////// Checkbox ////////////////////////////////////////////////////////////
	module("Dependencies Tests for Checkbox Fields.");
	test("Boolean Test", function() {
		var testElement = S('#field1_sub0 div[name=group1_i2c0_wakeup_en]'),
			dependenciesElement = S('#field1_sub0 div[name=group1_UART2EnableINTCheckbox]');

		equal(dependenciesElement.length, 3, 'control group1_UART2EnableINTCheckbox found.');
		if (testElement.length) {
			ok(true, 'test control found:' + testElement.length);
		}
		else {
			ok(false, 'test control not found');
		}
		equal(testElement.is(":visible"), false, 'control group1_i2c0_wakeup_en hidden.');
		if (dependenciesShow) {
			dependenciesElement[0].children[0].children[0].checked= true;
			dependenciesElement[1].children[0].children[0].checked= false;
			dependenciesElement[2].children[0].children[0].checked= false;
			dependenciesElement.change();
			S.wait(500, function() {
				equal(testElement.is(":visible"), true, 'control group1_i2c0_wakeup_en shown.');
			});
		}
	});
	test("Array Test", function() {
		var testElement = S('#field1_sub0 input:radio[name=group1_UART1BaudrateRadio]'),
			dependenciesElement = S('#field1_sub0 div[name=group1_UART2EnableINTCheckbox]');

		equal(dependenciesElement.length, 3, 'control group1_UART2EnableINTCheckbox found.');
		if (testElement.length) {
			ok(true, 'test control found:' + testElement.length);
		}
		else {
			ok(false, 'test control not found');
		}
		equal(testElement.is(":visible"), false, 'control group1_UART1BaudrateRadio hidden.');
		if (dependenciesShow) {
			dependenciesElement[0].children[0].children[0].checked= true;
			dependenciesElement[1].children[0].children[0].checked= true;
			dependenciesElement[2].children[0].children[0].checked= false;
			dependenciesElement.change();
			S.wait(500, function() {
				equal(testElement.is(":visible"), true, 'control group1_UART1BaudrateRadio shown.');
			});
		}
	});

	///////////////////////////////////////////// CheckboxBoolean ////////////////////////////////////////////////////////////
	module("Dependencies Tests for CheckboxBoolean Fields.");
	test("Single Test", function() {
		var testElement = S('#field1_sub0 div[name=group1_DepB1Radio]'),
			testElement1 = S('#field1_sub0 div[name=group1_DepC1Radio]'),
			dependenciesElement = S('#field1_sub0 div[name=group1_A1Checkbox]');

		equal(dependenciesElement.length, 1, 'control group1_A1Checkbox found.');
		ok(true, 'control group1_A1Checkbox value ' + dependenciesElement[0].children[0].children[0].checked);
		if (testElement.length) {
			ok(true, 'test control found:' + testElement.length);
		}
		else {
			ok(false, 'test control not found');
		}
		equal(testElement.is(":visible"), false, 'control group1_DepB1Radio hidden.');
		if (testElement1.length) {
			ok(true, 'test1 control found:' + testElement1.length);
		}
		else {
			ok(false, 'test1 control not found');
		}
		equal(testElement1.is(":visible"), true, 'control group1_DepC1Radio shown.');
		if (dependenciesShow) {
			dependenciesElement[0].children[0].children[0].checked= true;
			ok(true, 'control group1_A1Checkbox value ' + dependenciesElement[0].children[0].children[0].checked);
			dependenciesElement.change();
			S.wait(500, function() {
				equal(testElement.is(":visible"), true, 'control group1_DepB1Radio shown.');
				equal(testElement1.is(":visible"), false, 'control group1_DepC1Radio hidden.');
			});
		}
	});
	///////////////////////////////////////////// MultipleSelect ////////////////////////////////////////////////////////////
	module("Dependencies Tests for MultipleSelect Fields.");
	test("Single Test", function() {
		var testElement = S('#field1_sub0 div[name=group1_CLK_LxtFailDetectorIntCheckbox]'),
			dependenciesElement = S('#field1_sub0 select[name=group1_UART1DisableINTMultipleSelect]');

		equal(dependenciesElement.length, 1, 'control group1_UART1DisableINTMultipleSelect found.');
		ok(true, 'control group1_UART1DisableINTMultipleSelect value ' + dependenciesElement.val());
		if (testElement.length) {
			ok(true, 'test control found:' + testElement.length);
		}
		else {
			ok(false, 'test control not found');
		}
		equal(testElement.is(":visible"), false, 'control group1_CLK_LxtFailDetectorIntCheckbox hidden.');
		if (dependenciesShow) {
			dependenciesElement[0].value = "UART_INTEN_RDAIEN_Msk";
			dependenciesElement.change();
			ok(true, 'control group1_UART1DisableINTMultipleSelect value ' + dependenciesElement.val());
			S.wait(500, function() {
				equal(testElement.is(":visible"), true, 'control group1_CLK_LxtFailDetectorIntCheckbox shown.');
			});
		}
	})
	///////////////////////////////////////////// Integer ////////////////////////////////////////////////////////////
	module("Dependencies Tests for Integer Fields.");
	test("Compare Test", function() {
		var testElement = S('#field1_sub0 div[name=group1_CLK_HxtFrequencyDetectorIntCheckbox]'),
			dependenciesElement = S('#field1_sub0 input[name=group1_CLK_HxtFrequencyUpperBoundInteger]');

		equal(dependenciesElement.length, 1, 'control group1_CLK_HxtFrequencyUpperBoundInteger found.');
		ok(true, 'control group1_CLK_HxtFrequencyUpperBoundInteger value ' + dependenciesElement.val());
		if (testElement.length) {
			ok(true, 'test control found:' + testElement.length);
		}
		else {
			ok(false, 'test control not found');
		}
		equal(testElement.is(":visible"), false, 'control group1_CLK_HxtFrequencyDetectorIntCheckbox hidden.');
		if (dependenciesShow) {
			dependenciesElement[0].value = "550";
			dependenciesElement.change();
			ok(true, 'control group1_CLK_HxtFrequencyUpperBoundInteger value ' + dependenciesElement.val());
			S.wait(500, function() {
				equal(testElement.is(":visible"), true, 'control group1_CLK_HxtFrequencyDetectorIntCheckbox shown.');
			});
		}
	});
	///////////////////////////////////////////// HexText ////////////////////////////////////////////////////////////
	module("Dependencies Tests for HexText Fields.");
	test("Single Test", function() {
		var dependenciesShow = true;

		var testElement = S('#field1_sub0 div[name=group1_CLK_PowerDownCheckbox]'),
			dependenciesElement = S('#field1_sub0 input[name=group1_Timer0InputHexText]');

		equal(dependenciesElement.length, 1, 'control group1_Timer0InputHexText found.');
		ok(true, 'control group1_Timer0InputHexText value ' + dependenciesElement.val());
		if (testElement.length) {
			ok(true, 'test control found:' + testElement.length);
		}
		else {
			ok(false, 'test control not found');
		}
		equal(testElement.is(":visible"), false, 'control group1_CLK_PowerDownCheckbox hidden.');
		if (dependenciesShow) {
			dependenciesElement[0].value = "4800";
			dependenciesElement.change();
			ok(true, 'control group1_Timer0InputHexText value ' + dependenciesElement.val());
			S.wait(500, function() {
				equal(testElement.is(":visible"), true, 'control group1_CLK_PowerDownCheckbox shown.');
			});
		}
	});

	///////////////////////////////////////////// TwoToOne ////////////////////////////////////////////////////////////
	module("Dependencies Tests for TwoToOne Fields.");
	test("Boolean Test", function() {
		var testElement = S('#field1_sub0 select[name=group1_BPWM0CLKSRCSelect]'),
			dependenciesElement = S('#field1_sub0 select[name=group1_ADCOperationModeSelect]');

		equal(dependenciesElement.length, 1, 'control group1_ADCOperationModeSelect found.');
		ok(true, 'control group1_ADCOperationModeSelect value ' + dependenciesElement.val());
		if (testElement.length) {
			ok(true, 'test control found:' + testElement.length);
		}
		else {
			ok(false, 'test control not found');
		}
		equal(testElement.is(":visible"), false, 'control group1_BPWM0CLKSRCSelect hidden.');
		if (dependenciesShow) {
			dependenciesElement[0].value = 'ADC_OPERATION_MODE_SINGLE';
			dependenciesElement.change();
			ok(true, 'control group1_ADCOperationModeSelect value ' + dependenciesElement.val());
			S.wait(500, function() {
				equal(testElement.is(":visible"), true, 'control group1_BPWM0CLKSRCSelect shown.');
			});
		}
	})
	test("Array of Object of Boolean Test", function() {
		var testElement = S('#field1_sub0 select[name=group1_ADCCmp0ChannelSelect]'),
			dependenciesElement = S('#field1_sub0 select[name=group1_ADCOperationModeSelect]');

		equal(dependenciesElement.length, 1, 'control group1_ADCOperationModeSelect found.');
		ok(true, 'control group1_ADCOperationModeSelect value ' + dependenciesElement.val());
		if (testElement.length) {
			ok(true, 'test control found:' + testElement.length);
		}
		else {
			ok(false, 'test control not found');
		}
		equal(testElement.is(":visible"), false, 'control group1_ADCCmp0ChannelSelect hidden.');
		if (dependenciesShow) {
			dependenciesElement[0].value = 'ADC_OPERATION_MODE_CONTINUOUS';
			dependenciesElement.change();
			ok(true, 'control group1_ADCOperationModeSelect value ' + dependenciesElement.val());
			S.wait(500, function() {
				equal(testElement.is(":visible"), true, 'control group1_ADCCmp0ChannelSelect shown.');
			});
		}
	});
}(jQuery) );
