(function($) {
	var dependenciesShow = true;

	//return;
	///////////////////////////////////////////// Select ////////////////////////////////////////////////////////////
	module("Dependencies Tests for Select Fields.");
	test("Single Test", function() {
		var testElement = S('#field1_sub0 input[name=UART1BaudrateInteger]'),
			dependenciesElement = S('#field1_sub0 select[name=UART0BaudrateSelect]');

		equal(dependenciesElement.length, 1, 'control UART0BaudrateSelect found.');
		equal(dependenciesElement.val(), "9600", 'control UART0BaudrateSelect value 9600 checked.');
		if (testElement.length) {
			ok(true, 'test control found:' + testElement.length);
		}
		else {
			ok(false, 'test control not found');
		}
		equal(testElement.is(":visible"), false, 'control UART1BaudrateInteger hidden.');
		if (dependenciesShow) {
			dependenciesElement[0].value = "4800";
			dependenciesElement.change();
			equal(dependenciesElement.val(), "4800", 'control UART0BaudrateSelect value 4800 checked.');
			S.wait(500, function() {
				equal(testElement.is(":visible"), true, 'control UART1BaudrateInteger shown.');
			});
		}
	});
	test("Boolean Test", function() {
		var testElement = S('#field1_sub0 select[name=TIMER0OutputPinSelect]'),
			dependenciesElement = S('#field1_sub0 select[name=TIMER0ModeSelect]');

		equal(dependenciesElement.length, 1, 'control TIMER0ModeSelect found.');
		equal(dependenciesElement.val(), "TIMER_ONESHOT_MODE", 'control TIMER0ModeSelect value TIMER_ONESHOT_MODE checked.');
		if (testElement.length) {
			ok(true, 'test control found:' + testElement.length);
		}
		else {
			ok(false, 'test control not found');
		}
		equal(testElement.is(":visible"), false, 'control TIMER0OutputPinSelect hidden.');
		if (dependenciesShow) {
			dependenciesElement[0].value = "TIMER_PERIODIC_MODE";
			dependenciesElement.change();
			equal(dependenciesElement.val(), "TIMER_PERIODIC_MODE", 'control TIMER0ModeSelect value TIMER_PERIODIC_MODE checked.');
			S.wait(500, function() {
				equal(testElement.is(":visible"), true, 'control TIMER0OutputPinSelect shown.');
			});
		}
	});
	test("Object of Array Test", function() {
		var testElement = S('#field1_sub0 select[name=PDMACH2Destination1]'),
			dependenciesElement = S('#field1_sub0 select[name=PDMACH2Source]');

		equal(dependenciesElement.length, 1, 'control PDMACH2Source found.');
		equal(dependenciesElement.val(), "PDMA_MEM", 'control PDMACH2Source value PDMA_MEM checked.');
		if (testElement.length) {
			ok(true, 'test control found:' + testElement.length);
		}
		else {
			ok(false, 'test control not found');
		}
		equal(testElement.is(":visible"), false, 'control PDMACH2Destination1 hidden.');
		if (dependenciesShow) {
			dependenciesElement[0].value = "PDMA_UART0_RX";
			dependenciesElement.change();
			equal(dependenciesElement.val(), "PDMA_UART0_RX", 'control PDMACH2Source value PDMA_UART0_RX checked.');
			S.wait(500, function() {
				equal(testElement.is(":visible"), true, 'control PDMACH2Destination1 shown.');
			});
		}
	});
	///////////////////////////////////////////// Radio ////////////////////////////////////////////////////////////
	module("Dependencies Tests for Radio Fields.");
	test("Single Test", function() {
		var testElement = S('#field1_sub0 div[name=UART1EnableINTCheckbox]'),
			dependenciesElement = S('#field1_sub0 input:radio[name=UART0BaudrateRadio]'),
			dependenciesCheckedElement = S('#field1_sub0 input:radio[name=UART0BaudrateRadio]:checked');

		equal(dependenciesElement.length, 9, 'control UART0BaudrateRadio found.');
		equal(dependenciesCheckedElement.length, 1, "control UART0BaudrateRadio Checked found.");
		equal(dependenciesCheckedElement.val(), "57600", 'control UART0BaudrateRadio value 57600 checked.');
		if (testElement.length) {
			ok(true, 'test control found:' + testElement.length);
		}
		else {
			ok(false, 'test control not found');
		}
		equal(testElement.is(":visible"), false, 'control UART1EnableINTCheckbox hidden.');
		if (dependenciesShow) {
			dependenciesElement[4].checked = false;
			dependenciesElement[5].checked = true;
			dependenciesElement.change();
			dependenciesCheckedElement = S('#field1_sub0 input:radio[name=UART0BaudrateRadio]:checked');
			equal(dependenciesCheckedElement.length, 1, "control UART0BaudrateRadio Checked found.");
			equal(dependenciesCheckedElement.val(), "115200", 'control UART0BaudrateRadio value 115200 checked.');
			S.wait(500, function() {
				equal(testElement.is(":visible"), true, 'control UART1EnableINTCheckbox shown.');
			});
		}
	});
	test("Boolean Test", function() {
		var testElement = S('#field1_sub0 div[name=CLK_DPDWKPIN0Checkbox]'),
			dependenciesElement = S('#field1_sub0 input:radio[name=CLK_PowerDownModeRadio]'),
			dependenciesCheckedElement = S('#field1_sub0 input:radio[name=CLK_PowerDownModeRadio]:checked');

		equal(dependenciesElement.length, 3, 'control CLK_PowerDownModeRadio found.');
		equal(dependenciesCheckedElement.length, 1, "control CLK_PowerDownModeRadio Checked found.");
		equal(dependenciesCheckedElement.val(), "CLK_PMUCTL_PDMSEL_PD", 'control CLK_PowerDownModeRadio value CLK_PMUCTL_PDMSEL_PD checked.');
		if (testElement.length) {
			ok(true, 'test control found:' + testElement.length);
		}
		else {
			ok(false, 'test control not found');
		}
		equal(testElement.is(":visible"), false, 'control CLK_DPDWKPIN0Checkbox hidden.');
		if (dependenciesShow) {
			dependenciesElement[0].checked = false;
			dependenciesElement[1].checked = true;
			dependenciesElement.change();
			dependenciesCheckedElement = S('#field1_sub0 input:radio[name=CLK_PowerDownModeRadio]:checked');
			equal(dependenciesCheckedElement.length, 1, "control CLK_PowerDownModeRadio Checked found.");
			equal(dependenciesCheckedElement.val(), "CLK_PMUCTL_PDMSEL_FWPD", 'control CLK_PowerDownModeRadio value CLK_PMUCTL_PDMSEL_FWPD checked.');
			S.wait(500, function() {
				equal(testElement.is(":visible"), true, 'control CLK_DPDWKPIN0Checkbox shown.');
			});
		}
	})
	///////////////////////////////////////////// Checkbox ////////////////////////////////////////////////////////////
	module("Dependencies Tests for Checkbox Fields.");
	test("Boolean Test", function() {
		var testElement = S('#field1_sub0 div[name=i2c0_wakeup_en]'),
			dependenciesElement = S('#field1_sub0 div[name=UART2EnableINTCheckbox]');

		equal(dependenciesElement.length, 3, 'control UART2EnableINTCheckbox found.');
		if (testElement.length) {
			ok(true, 'test control found:' + testElement.length);
		}
		else {
			ok(false, 'test control not found');
		}
		equal(testElement.is(":visible"), false, 'control i2c0_wakeup_en hidden.');
		if (dependenciesShow) {
			dependenciesElement[0].children[0].children[0].checked= true;
			dependenciesElement[1].children[0].children[0].checked= false;
			dependenciesElement[2].children[0].children[0].checked= false;
			dependenciesElement.change();
			S.wait(500, function() {
				equal(testElement.is(":visible"), true, 'control i2c0_wakeup_en shown.');
			});
		}
	});
	test("Array Test", function() {
		var testElement = S('#field1_sub0 input:radio[name=UART1BaudrateRadio]'),
			dependenciesElement = S('#field1_sub0 div[name=UART2EnableINTCheckbox]');

		equal(dependenciesElement.length, 3, 'control UART2EnableINTCheckbox found.');
		if (testElement.length) {
			ok(true, 'test control found:' + testElement.length);
		}
		else {
			ok(false, 'test control not found');
		}
		equal(testElement.is(":visible"), false, 'control UART1BaudrateRadio hidden.');
		if (dependenciesShow) {
			dependenciesElement[0].children[0].children[0].checked= true;
			dependenciesElement[1].children[0].children[0].checked= true;
			dependenciesElement[2].children[0].children[0].checked= false;
			dependenciesElement.change();
			S.wait(500, function() {
				equal(testElement.is(":visible"), true, 'control UART1BaudrateRadio shown.');
			});
		}
	});
	///////////////////////////////////////////// CheckboxBoolean ////////////////////////////////////////////////////////////
	module("Dependencies Tests for CheckboxBoolean Fields.");
	test("Single Test", function() {
		var testElement = S('#field1_sub0 div[name=DepB1Radio]'),
			testElement1 = S('#field1_sub0 div[name=DepC1Radio]'),
			dependenciesElement = S('#field1_sub0 div[name=A1Checkbox]');

		equal(dependenciesElement.length, 1, 'control A1Checkbox found.');
		ok(true, 'control A1Checkbox value ' + dependenciesElement[0].children[0].children[0].checked);
		if (testElement.length) {
			ok(true, 'test control found:' + testElement.length);
		}
		else {
			ok(false, 'test control not found');
		}
		equal(testElement.is(":visible"), false, 'control DepB1Radio hidden.');
		if (testElement1.length) {
			ok(true, 'test1 control found:' + testElement1.length);
		}
		else {
			ok(false, 'test1 control not found');
		}
		equal(testElement1.is(":visible"), true, 'control DepC1Radio shown.');
		if (dependenciesShow) {
			dependenciesElement[0].children[0].children[0].checked= true;
			ok(true, 'control A1Checkbox value ' + dependenciesElement[0].children[0].children[0].checked);
			dependenciesElement.change();
			S.wait(500, function() {
				equal(testElement.is(":visible"), true, 'control DepB1Radio shown.');
				equal(testElement1.is(":visible"), false, 'control DepC1Radio hidden.');
			});
		}
	});
	///////////////////////////////////////////// MultipleSelect ////////////////////////////////////////////////////////////
	module("Dependencies Tests for MultipleSelect Fields.");
	test("Single Test", function() {
		var testElement = S('#field1_sub0 div[name=CLK_LxtFailDetectorIntCheckbox]'),
			dependenciesElement = S('#field1_sub0 select[name=UART1DisableINTMultipleSelect]');

		equal(dependenciesElement.length, 1, 'control UART1DisableINTMultipleSelect found.');
		ok(true, 'control UART1DisableINTMultipleSelect value ' + dependenciesElement.val());
		if (testElement.length) {
			ok(true, 'test control found:' + testElement.length);
		}
		else {
			ok(false, 'test control not found');
		}
		equal(testElement.is(":visible"), false, 'control CLK_LxtFailDetectorIntCheckbox hidden.');
		if (dependenciesShow) {
			dependenciesElement[0].value = "UART_INTEN_RDAIEN_Msk";
			dependenciesElement.change();
			ok(true, 'control UART1DisableINTMultipleSelect value ' + dependenciesElement.val());
			S.wait(500, function() {
				equal(testElement.is(":visible"), true, 'control CLK_LxtFailDetectorIntCheckbox shown.');
			});
		}
	})
	///////////////////////////////////////////// Integer ////////////////////////////////////////////////////////////
	module("Dependencies Tests for Integer Fields.");
	test("Compare Test", function() {
		var testElement = S('#field1_sub0 div[name=CLK_HxtFrequencyDetectorIntCheckbox]'),
			dependenciesElement = S('#field1_sub0 input[name=CLK_HxtFrequencyUpperBoundInteger]');

		equal(dependenciesElement.length, 1, 'control CLK_HxtFrequencyUpperBoundInteger found.');
		ok(true, 'control CLK_HxtFrequencyUpperBoundInteger value ' + dependenciesElement.val());
		if (testElement.length) {
			ok(true, 'test control found:' + testElement.length);
		}
		else {
			ok(false, 'test control not found');
		}
		equal(testElement.is(":visible"), false, 'control CLK_HxtFrequencyDetectorIntCheckbox hidden.');
		if (dependenciesShow) {
			dependenciesElement[0].value = "550";
			dependenciesElement.change();
			ok(true, 'control CLK_HxtFrequencyUpperBoundInteger value ' + dependenciesElement.val());
			S.wait(500, function() {
				equal(testElement.is(":visible"), true, 'control CLK_HxtFrequencyDetectorIntCheckbox shown.');
			});
		}
	});
	///////////////////////////////////////////// HexText ////////////////////////////////////////////////////////////
	module("Dependencies Tests for HexText Fields.");
	test("Single Test", function() {
		var testElement = S('#field1_sub0 div[name=CLK_PowerDownCheckbox]'),
			dependenciesElement = S('#field1_sub0 input[name=Timer0InputHexText]');

		equal(dependenciesElement.length, 1, 'control Timer0InputHexText found.');
		ok(true, 'control Timer0InputHexText value ' + dependenciesElement.val());
		if (testElement.length) {
			ok(true, 'test control found:' + testElement.length);
		}
		else {
			ok(false, 'test control not found');
		}
		equal(testElement.is(":visible"), false, 'control CLK_PowerDownCheckbox hidden.');
		if (dependenciesShow) {
			dependenciesElement[0].value = "4800";
			dependenciesElement.change();
			ok(true, 'control Timer0InputHexText value ' + dependenciesElement.val());
			S.wait(500, function() {
				equal(testElement.is(":visible"), true, 'control CLK_PowerDownCheckbox shown.');
			});
		}
	});
	///////////////////////////////////////////// TwoToOne ////////////////////////////////////////////////////////////
	module("Dependencies Tests for TwoToOne Fields.");
	test("Boolean Test", function() {
		var testElement = S('#field1_sub0 select[name=BPWM0CLKSRCSelect]'),
			dependenciesElement = S('#field1_sub0 select[name=ADCOperationModeSelect]');

		equal(dependenciesElement.length, 1, 'control ADCOperationModeSelect found.');
		ok(true, 'control ADCOperationModeSelect value ' + dependenciesElement.val());
		if (testElement.length) {
			ok(true, 'test control found:' + testElement.length);
		}
		else {
			ok(false, 'test control not found');
		}
		equal(testElement.is(":visible"), false, 'control BPWM0CLKSRCSelect hidden.');
		if (dependenciesShow) {
			dependenciesElement[0].value = 'ADC_OPERATION_MODE_SINGLE';
			dependenciesElement.change();
			ok(true, 'control ADCOperationModeSelect value ' + dependenciesElement.val());
			S.wait(500, function() {
				equal(testElement.is(":visible"), true, 'control BPWM0CLKSRCSelect shown.');
			});
		}
	})
	test("Array of Object of Boolean Test", function() {
		var testElement = S('#field1_sub0 select[name=ADCCmp0ChannelSelect]'),
			dependenciesElement = S('#field1_sub0 select[name=ADCOperationModeSelect]');

		equal(dependenciesElement.length, 1, 'control ADCOperationModeSelect found.');
		ok(true, 'control ADCOperationModeSelect value ' + dependenciesElement.val());
		if (testElement.length) {
			ok(true, 'test control found:' + testElement.length);
		}
		else {
			ok(false, 'test control not found');
		}
		equal(testElement.is(":visible"), false, 'control ADCCmp0ChannelSelect hidden.');
		if (dependenciesShow) {
			dependenciesElement[0].value = 'ADC_OPERATION_MODE_CONTINUOUS';
			dependenciesElement.change();
			ok(true, 'control ADCOperationModeSelect value ' + dependenciesElement.val());
			S.wait(500, function() {
				equal(testElement.is(":visible"), true, 'control ADCCmp0ChannelSelect shown.');
			});
		}
	});
}(jQuery) );
